#include<linux/kernel.h>
#include<linux/module.h>
#include<linux/init.h>

static int __init Hello_init(void){
pr_info("This is the beginnign of the hello world\n");
return 0;
}

static void __exit Hello_exit(void){
pr_info(" This is the end of the module\n");
}

module_init(Hello_init);
module_exit(Hello_exit);


MODULE_LICENSE("GPL");
MODULE_AUTHOR("Rejin");

