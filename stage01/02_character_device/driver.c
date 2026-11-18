#include<linux/kernel.h>
#include<linux/module.h>
#include<linux/fs.h>
#include<linux/kdev_t.h>
#include<linux/init.h>
#include<linux/device.h>

dev_t dev;
static struct class *dev_class;


static int __init driver_file_init(void)
{
if (alloc_chrdev_region(&dev,0,1,"dev_Rejin") < 0) {
pr_err("Failed allocation of the device numbers\n");
return -1;
}
pr_info(" the module beginning \n");
dev_class=class_create("class_REJIN");

if(IS_ERR(dev_class)){
pr_err("Cannot create the class\n");
goto r_class;
}

if(IS_ERR(device_create(dev_class,NULL,dev,NULL,"device_Rejin")))
{
pr_err("Failed to create the device node\n");
goto r_device;

}

return 0;

r_device:
	device_destroy(dev_class,dev);

r_class:
	class_destroy(dev_class);

return -1;
}

static void __exit driver_file_exit(void)
{
device_destroy(dev_class,dev);
class_destroy(dev_class);
unregister_chrdev_region(dev,1);
pr_info("The device is closed or removed\n");
}

module_init(driver_file_init);
module_exit(driver_file_exit);

MODULE_LICENSE("GPL");

