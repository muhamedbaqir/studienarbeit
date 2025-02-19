#include <linux/module.h> /* Needed by all modules */ 
#include <linux/printk.h> /* Needed for pr_info() */ 
#include <linux/vmalloc.h>

void test_vmalloc(void);

int init_module(void) 

{ 

    pr_info("Custom ramdisk module"); 
    test_vmalloc();

    /* A non 0 return means init_module failed; module can't be loaded. */ 

    return 0; 

} 

void test_vmalloc(void){
	int size = 100;
	char *ptr = vmalloc(size);
	if(!ptr)pr_err("error while trying to vmalloc \n");
	else {
		strcpy(ptr,"hello world string");
		pr_err("string is %s",ptr);
		vfree(ptr);
	}
}

 

void cleanup_module(void) 

{ 

    pr_info("Goodbye world 1.\n"); 

} 

 

MODULE_LICENSE("GPL");
