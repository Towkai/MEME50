#include<linux/kernel.h> //for kernel alert
#include<linux/module.h>
#include<linux/init.h> //for __init and __exit

static int __init hello_init(void) {
    // printk("\0011" "Hello World\n");
    printk(KERN_ALERT "Hello World\n");
    return 0;
}

static void __exit hello_exit(void) {
    printk("bye \n");
}

module_init(hello_init);
module_exit(hello_exit);
MODULE_LICENSE("GPL");