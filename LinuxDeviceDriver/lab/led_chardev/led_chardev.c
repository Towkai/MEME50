#include <linux/version.h>
#include <linux/module.h>  
#include <linux/kernel.h>  
#include <linux/fs.h>
#include <linux/init.h>  
#include <linux/major.h>  
#include <linux/device.h>  
#include <linux/poll.h>  
#include <linux/io.h>  
#include <linux/delay.h>  
 
#include <linux/uaccess.h> /* for put_user */

#if LINUX_VERSION_CODE > KERNEL_VERSION(2,6,0)
#include <linux/cdev.h>
static struct cdev mycdev;
#endif

#define SUCCESS 0
#define DEVICE_NAME "rpi_led"
int Major;

struct io_windows {
	unsigned long phys_base;
	unsigned long len;
};

uint32_t *PERIBase;
uint32_t *GPIOBase;
uint32_t *RIOBase;
uint32_t *PADBase;
uint32_t *pad;

typedef struct{
    uint32_t status;
    uint32_t ctrl; 
}GPIOregs;

#define GPIO ((GPIOregs*)GPIOBase)

typedef struct
{
    uint32_t Out;
    uint32_t OE;
    uint32_t In;
    uint32_t InSync;
} rioregs;

#define rio ((rioregs *)RIOBase)
#define rioXOR ((rioregs *)(RIOBase + 0x1000 / 4))
#define rioSET ((rioregs *)(RIOBase + 0x2000 / 4))
#define rioCLR ((rioregs *)(RIOBase + 0x3000 / 4))

static struct class *charmodule_class; 
// To do: set the GPIO port to control
uint32_t pin = 23;  // GPIO23
uint32_t fn = 5;

static int led_open(struct inode *inode, struct file *file)
{
    printk("led_open() Set the GPIO23 as RIO\n");

/*    printk("led_open() GPIO[pin].ctrl:%x", GPIO[pin].ctrl);
    printk("led_open() pad[pin]:%x", pad[pin]);
    printk("led_open() rioSET->OE:%x", rioSET);
    printk("led_open() rioSET->Out:%x", rioSET);
*/
    /* To do: Set the GPIO pin as RIO, function, Output enable, Output high */

    return SUCCESS;
}
static int led_release(struct inode *inode, struct file *file)
{
    printk("led_release() Toggle the LED\n");
    return 0;
}
/* Called when a process, which already opened the dev file, attempts to read from it. 
 * struct file *filp: the file operation
 * char *buffer: The buffer to fill with data
 * size_t length: The length of the buffer
 * loff_t *offset: Our offset in the file
 */
static ssize_t led_read(struct file *filp, char *buffer, size_t length, loff_t *offset)
{
    int bytes_read = 0;

    printk("led_read() Toggle the GPIO23, pin:%d, rioXOR->Out:%x\n", pin, rioXOR);
    // To do: Toggle the GPIO23 and do a small delay


    return bytes_read;
}
/* Called when a process writes to dev file: echo "hi" > /dev/led */
static ssize_t led_write(struct file *filp, const char *buff, size_t len, loff_t *off)
{
    // To do: clear the GPIO23
    rioCLR->Out = 1<<pin; 
    mdelay(500);
    printk ("Sorry, this operation isn't supported.\n");
    return -EINVAL;
}


static struct file_operations fops = {
    .read = led_read,
    .write = led_write,
    .open = led_open,
    .release = led_release
};
// Functions

int __init init_module(void)
{
#if LINUX_VERSION_CODE > KERNEL_VERSION(2,6,0)
    dev_t devno=0;

    if(Major) {
        if ( register_chrdev_region(MKDEV(Major,0), 1, DEVICE_NAME) < 0 ) {
            printk ("register_chrdev_region() fail\n");
           goto fail_register_chrdev;
        }
    }
    else {
        if (alloc_chrdev_region(&devno, 0, 1, DEVICE_NAME) < 0) {
           printk ("alloc_chrdev_region() fail\n");
           goto fail_register_chrdev;
        }
        Major=MAJOR(devno);
    }
    cdev_init(&mycdev, &fops);
    mycdev.owner=THIS_MODULE;
    if(cdev_add(&mycdev, MKDEV(Major,0), 1)) {
        printk ("Error adding cdev\n");
           goto fail_cdev_add;
    }
#else
    Major = register_chrdev(0, DEVICE_NAME, &fops);
    if (Major < 0) {
        printk ("Registering the character device failed with %d\n", Major);
        return -1;
    }
#endif

    /* To do: create your own class under /sysfs */
#if LINUX_VERSION_CODE < KERNEL_VERSION(6,4,0)
    charmodule_class = class_create(THIS_MODULE, "charmodule_class");
#else
    charmodule_class = class_create("charmodule_class"); 
#endif

    if(IS_ERR(charmodule_class)) {
      printk("Err: failed in creating class.\n");
      return -1;
    }

     /* To do: register your own device in sysfs, and this will cause udev to create corresponding device node */
#if LINUX_VERSION_CODE > KERNEL_VERSION(2,6,27)
    int i=0;
    device_create(charmodule_class, NULL, MKDEV(Major, i), NULL, "led%d", i);
    i++;
#elif LINUX_VERSION_CODE > KERNEL_VERSION(2,6,9)
    device_create(charmodule_class, NULL, MKDEV(Major, 0), "led"); 
#else
    class_simple_device_add( charmodule_class, MKDEV(Major, 0), NULL, "led" );
#endif
    printk(KERN_ALERT"'mknod /dev/led c %d 0'.\n", Major);

    // To do: Use ioremap to map the physical address into virtual address
 
    if ( PERIBase == NULL ) {
        printk("ioremap() fail\n");
	goto failed_ioremap;
    }
    GPIOBase = PERIBase + 0xD0000 / 4;
    RIOBase = PERIBase + 0xe0000 / 4;
    PADBase = PERIBase + 0xf0000 / 4;
    pad = PADBase + 1 ;

    printk("PERIBase:%x\n", PERIBase);    
    printk("GPIOBase:%x\n", GPIOBase);    
    printk("RIOBase:%x\n", RIOBase);    
    printk("PADBase:%x\n", PADBase);
    printk("pad:%x\n", pad);

    return 0;

failed_ioremap:
    device_destroy(charmodule_class, MKDEV(Major, 0)); 
    class_destroy(charmodule_class); 
fail_cdev_add:
fail_register_chrdev:
    return -1;
}

void __exit cleanup_module(void)
{
    // To do: Unmap the virtual address
    iounmap(PERIBase);
#if LINUX_VERSION_CODE > KERNEL_VERSION(2,6,9)
    // To do: delete device node under /dev
    device_destroy(charmodule_class, MKDEV(Major, 0)); 
    // To do: delete class created by us
    class_destroy(charmodule_class); 
#else
    class_simple_device_remove(MKDEV(Major, 0));
    class_simple_destroy(charmodule_class);
#endif
#if LINUX_VERSION_CODE > KERNEL_VERSION(2,6,0)
    cdev_del(&mycdev);
    unregister_chrdev_region(MKDEV(Major, 0), 1);
#else
    /* Unregister the device */
    unregister_chrdev(Major, DEVICE_NAME);
#endif
    printk("unregister_chrdev\n");
}

MODULE_LICENSE ("GPL");
