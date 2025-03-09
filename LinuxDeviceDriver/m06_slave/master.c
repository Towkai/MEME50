#include<linux/kernel.h>
#include<linux/module.h>
#include<linux/init.h> //for __init and __exit
#include<linux/kmod.h> //for request_module
#include"slave.h"

static int __init master_init(void) {
    slave_test(); ///form slave.h <<EXPORT_SYMBOL>>
    return 0;
}

static void __exit master_exit(void) {}

module_init(master_init);
module_exit(master_exit);
MODULE_LICENSE("GPL");
