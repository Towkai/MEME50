#include <linux/version.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/fs.h>
#include <linux/uaccess.h> /* for put_user */
#if LINUX_VERSION_CODE > KERNEL_VERSION(2,6,0)
#include <linux/cdev.h>
static dev_t devno=0;
static struct cdev mycdev;
#endif
/* Prototypes - this would normally go in a .h file */
int init_module(void);
void cleanup_module(void);
static int device_open(struct inode *, struct file *);
static int device_release(struct inode *, struct file *);
static ssize_t device_read(struct file *, char *, size_t, loff_t *);
static ssize_t device_write(struct file *, const char *, size_t, loff_t *);

#define SUCCESS 0
#define DEVICE_NAME "memdev" /* Dev name as it appears in /proc/devices */
#define BUF_LEN 80
#define DEV_NUM 2

// Global variables are declared as static, so are global within the file.
static int Major=0; // Major number assigned to our device driver

static char Message[DEV_NUM][BUF_LEN], *msg_Ptr; // The Message the device will give when asked
static struct file_operations fops = {
    .read = device_read,
    .write = device_write,
    .open = device_open,
    .release = device_release
};
// Functions
int init_module(void)
{
    int i;

#if LINUX_VERSION_CODE > KERNEL_VERSION(2,6,0)
    if(Major) {
        if ( register_chrdev_region(MKDEV(Major,0), DEV_NUM, DEVICE_NAME) < 0 ) {
            printk ("register_chrdev_region() fail\n");
            return -1;
        }
    }
    else {
        if (alloc_chrdev_region(&devno, 0, DEV_NUM, DEVICE_NAME) < 0) {
           printk ("alloc_chrdev_region() fail\n");
           return -1;
        }
        Major=MAJOR(devno);
    }
    cdev_init(&mycdev, &fops);
    mycdev.owner=THIS_MODULE;
    if(cdev_add(&mycdev, MKDEV(Major,0), DEV_NUM)) {
        printk ("Error adding cdev\n");
    }
#else
    Major = register_chrdev(0, DEVICE_NAME, &fops);
    if (Major < 0) {
        printk ("Registering the character device failed with %d\n", Major);
        return -1;
    }
#endif
    printk("I was assigned major number %d. To talk to\n", Major);
    printk("the driver, create a dev file with\n");
    printk("'mknod /dev/hello c %d 0'.\n", Major);
    printk("Try various minor numbers. Try to cat and echo to\n");
    printk("the device file.\n");
    printk("Remove the device file and module when done.\n");

    /* To do: Cleanup the Memory devide */

    return 0;
}

void cleanup_module(void)
{
#if LINUX_VERSION_CODE > KERNEL_VERSION(2,6,0)
    cdev_del(&mycdev);
    unregister_chrdev_region(MKDEV(Major, 0), DEV_NUM);
#else
    /* Unregister the device */
    unregister_chrdev(Major, DEVICE_NAME);
#endif
    printk("unregister_chrdev\n");
}
static int device_open(struct inode *inode, struct file *file)
{
    //static int counter = 0;
    int dev_minor = iminor(inode);

    printk(KERN_ALERT "device_open(): dev_minor=%d\n", dev_minor);

    return SUCCESS;
}
static int device_release(struct inode *inode, struct file *file)
{
    return 0;
}
/* Called when a process, which already opened the dev file, attempts to read from it. 
 * struct file *filp: the file operation
 * char *buffer: The buffer to fill with data
 * size_t length: The length of the buffer
 * loff_t *offset: Our offset in the file
 */
static ssize_t device_read(struct file *filp, char *buff, size_t length, loff_t *offset)
{
    int bytes_read = 0;

    // To do: msg_Ptr point to the device to read.


    if (*msg_Ptr == 0) 
        return 0;

    while (length && *msg_Ptr) {
        put_user(*(msg_Ptr++), buff++);
        length--;
        bytes_read++;
    }

    return bytes_read;
}
/* Called when a process writes to dev file: echo "hi" > /dev/hello */
static ssize_t device_write(struct file *filp, const char *buff, size_t len, loff_t *off)
{
    int i;

    // To do: msg_Ptr point to the device to write.

    for( i=0; i<len && i<BUF_LEN ; i++) {
      get_user(*(msg_Ptr+i), buff+i);
    }

    return i;
}
MODULE_LICENSE("GPL");
