#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/init.h>

void __exit hello_exit(void) {
	printk("bye\n");
}
module_exit(hello_exit);

MODULE_LICENSE("GPL");
