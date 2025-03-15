#include <linux/version.h>
#include <linux/kernel.h> // need for kernel alert
#include <linux/module.h>
#include <linux/init.h>    // need for __init and __exit
#include <linux/uaccess.h> // for ssize_t
#include <linux/fs.h>      // for struct file_operations
#include <linux/uaccess.h> // for put_user
#if LINUX_VERSION_CODE > KERNEL_VERSION(2, 6, 0)
#include <linux/cdev.h>
static dev_t devno = 0;
static struct cdev mycdev;
#endif
#define DEVICE_NAME "hello" /* Dev name as it appears in /proc/devices */
#define ID "MEME5014"
#define BUFFER_SIZE 32

static int Major = 201;
static char myID[BUFFER_SIZE] = ID;
MODULE_PARM_DESC(myID, "My ID in iSpan\n");

int dev_open(struct inode *inode, struct file *fs)
{
    printk(KERN_INFO KERN_INFO "[dev_open]myID = %s\n", ID);
    strcpy(myID, ID);

    return 0;
}

int dev_release(struct inode *inode, struct file *fs)
{
    printk(KERN_INFO KERN_INFO "dev_release\n");

    return 0;
}

ssize_t dev_read(struct file *fs, char __user *buffer, size_t size, loff_t *lo)
{
    printk(KERN_INFO KERN_INFO "dev_read\n");
    int bytes_read = 0;
    if (*myID == 0)
        return 0;
    while (bytes_read < size && *myID)
    {
        if (put_user(*myID, buffer++))
            return -EFAULT;
        bytes_read++;
        (*myID)++;
    }
    if (size)
    {
        put_user('\n', buffer++);
        bytes_read++;
    }
    return bytes_read;

    return 0;
}

ssize_t dev_write(struct file *fs, const char __user *buffer, size_t size, loff_t *lo)
{
    printk(KERN_INFO KERN_INFO "dev_write\n");
    int i = 0;
    while (i < min(size, BUFFER_SIZE)) {
        get_user(*(myID+i),buffer+i);
        i++;
    }
    return i;
}

static struct file_operations fops = {
    .read = dev_read,
    .write = dev_write,
    .open = dev_open,
    .release = dev_release};

static int __init hello_init(void)
{
#if LINUX_VERSION_CODE > KERNEL_VERSION(2, 6, 0)
    if (Major)
    {
        if (register_chrdev_region(MKDEV(Major, 0), 1, DEVICE_NAME) < 0)
        {
            printk(KERN_INFO "register_chrdev_region() fail\n");
            return -1;
        }
    }
    else
    {
        if (alloc_chrdev_region(&devno, 0, 1, DEVICE_NAME) < 0)
        {
            printk(KERN_INFO "alloc_chrdev_region() fail\n");
            return -1;
        }
        Major = MAJOR(devno);
    }
    cdev_init(&mycdev, &fops);
    mycdev.owner = THIS_MODULE;
    if (cdev_add(&mycdev, MKDEV(Major, 0), 1))
    {
        printk(KERN_INFO "Error adding cdev\n");
    }
#else
    Major = register_chrdev(0, DEVICE_NAME, &fops);
    if (Major < 0)
    {
        printk(KERN_INFO "Registering the character device failed with %d\n", Major);
        return -1;
    }
#endif
    printk(KERN_INFO "I was assigned Mr number %d. To talk to\n", Major);
    printk(KERN_INFO "the driver, create a dev file with\n");
    printk(KERN_INFO "'mknod /dev/hello c %d 0'.\n", Major);
    printk(KERN_INFO "Try various minor numbers. Try to cat and echo to\n");
    printk(KERN_INFO "the device file.\n");
    printk(KERN_INFO "Remove the device file and module when done.\n");
    return 0;
}

static void __exit hello_exit(void)
{
#if LINUX_VERSION_CODE > KERNEL_VERSION(2, 6, 0)
    cdev_del(&mycdev);
    unregister_chrdev_region(MKDEV(Major, 0), 1);
#else
    /* Unregister the device */
    unregister_chrdev(Major, DEVICE_NAME);
#endif
    printk(KERN_INFO "unregister_chrdev\n");
}

module_init(hello_init);
module_exit(hello_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("RRMJ2137@gmail.com");
MODULE_DESCRIPTION("Register Character Driver!");
