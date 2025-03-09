#include<linux/version.h>   //for LINUX_VERSION_CODE
#include<linux/module.h>
#include<linux/kernel.h>
#include<linux/init.h>


///---宣告全域變數作為模組參數
static int myint = 20;
static char mybyte = 'A';
static char* mystring = "blah";
static int myintArray[2] = { 0, 420 };
///---

///---傳遞陣列
static int num_myinyArray = 0;
module_param(mybyte, byte, 0);
module_param(myint, int, S_IRSUR | SIWUSR | S_IRGRP | S_IROTH);
module_param(mystring, charp, 0);
#if LINUX_VERSION_CODE > KERNEL_VERSION(2,6,0)
MODULE_PARM(myintArray, "1-2i");
#endif
///---

///---
module_param(mybyte, byte, 0);
MODULE_PARM_DESC(myshort, "This short is important");
///---

static int __init hello_init(void) {
    printk(KERN_ALERT "mybyte is an 8 bit integer: %i\n", mybyte);
    printk(KERN_ALERT "myint is an integer: %i\n", myint);
    printk(KERN_ALERT "mystring is an string: %s\n", mystring);
#if LINUX_VERSION_CODE > KERNEL_VERSION(2,6,0)
    printk(KERN_ALERT "got %d elements for myintArray\n", num_myinyArray);
#endif
    printk(KERN_ALERT "myintArray is %i and %i\n", myintArray[0], myintArray[1]);
    return 0;
}
static void __exit hello_exit(void) {
    printk(KERN_ALERT "goodbye, world 5\n");
}
module_init(hello_init);
module_exit(hello_exit);
MODULE_LICENSE("GPL");
