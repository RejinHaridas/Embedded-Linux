#include<linux/kernel.h>
#include<linux/module.h>
#include<linux/fs.h>
#include<linux/init.h>

dev_t dev ;

static int __init driver_init(void){
pr_info("Begining of this module for device number dynamic allocation\n");
if(alloc_chrdev_region(&dev,0,1,"dev_Rejin") < 0){
pr_info("Failed\n");
return -1;
}
pr_info("The device numbers are Major = %d and Minor = %d ",MAJOR(dev),MINOR(dev));
return 0;
}

static void __exit driver_exit(void){
unregister_chrdev_region(dev,1);
pr_info("The module exited successfully\n");
} 

module_init(driver_init);
module_exit(driver_exit);

MODULE_LICENSE("GPL");

