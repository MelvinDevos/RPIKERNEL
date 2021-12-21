/*
 *  hello-5.c - Demonstrates command line argument passing to a module.
 */
#include <linux/module.h>
#include <linux/moduleparam.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/stat.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Melvin Devos");

static int gpio_array[20];
static int level_array[20];
static int toggle_array[20];

static int arr_argc = 0;

/*
 * module_param_array(name, type, num, perm);
 * The first param is the parameter's (in this case the array's) name
 * The second param is the data type of the elements of the array
 * The third argument is a pointer to the variable that will store the number 
 * of elements of the array initialized by the user at module loading time
 * The fourth argument is the permission bits
 */

module_param_array(gpio_array, int, &arr_argc, 0000);
MODULE_PARM_DESC(gpio_array, "An array of integers");

module_param_array(level_array, int, &arr_argc, 0000);
MODULE_PARM_DESC(level_array, "An array of integers");

module_param_array(toggle_array, int, &arr_argc, 0000);
MODULE_PARM_DESC(toggle_array, "An array of integers");

static int __init hello_5_init(void)
{
    int i;

    for (i = 0; i < arr_argc; i++)
    {
        printk(KERN_INFO "myintArray[%d] = %d\n", i, gpio_array[i]);
    }
    printk(KERN_INFO "got %d arguments for myintArray.\n", arr_argc);
    return 0;
}

static void __exit hello_5_exit(void)
{
    printk(KERN_INFO "Goodbye, world 5\n");
}

module_init(hello_5_init);
module_exit(hello_5_exit);