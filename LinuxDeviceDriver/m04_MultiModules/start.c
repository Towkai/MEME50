#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/init.h>

//#define __TEST__

int __init hello_init(void) {
#ifdef __TEST__
	printk("hello\n");
#endif

	printk(KERN_ALERT "hello! world\n");

	return 0;
}
module_init(hello_init);

MODULE_LICENSE("GPL");
