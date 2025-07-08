#include <linux/module.h>
#include <linux/init.h>
#include <linux/mod_devictable.h>
#include <linux/property.h>
#include <linux/platform_device.h>
#include <linux/of_device.h>
#include <linux/gpio/consumer.h>
/* Meta Information */
MODULE_LICENSE("GPL");
MODULE_AUTHOR("Rynxie");
MODULE_DESCRIPTION("General ILI9341 Driver");


static int ili9341_probe(struct platform_device *pdev);
static int ili9341_remove(struct platform_device *pdev);

static struct of_device_id ili9341_dt_ids[] = {
    {
    .compatible = "ili9341",
    }, { /* sentinel */ }
};
MODULE_DEVICE_TABLE(of, ili9341_dt_ids);

static struct platform_driver ili9341_driver = {
    .probe = ili9341_probe,
    .remove = ili9341_remove,
    .driver = {
        .name = "ili9341 driver",
        .of_match_table = ili9341_dt_ids,
    },
};

//GPIOs

static struct gpio_desc * backlightPin  = NULL;
static struct gpio_desc * dcPin         = NULL;
static struct gpio_desc * resetPin      = NULL;

static int ili9341_probe(struct platform_device *pdev){
    struct device *dev ? &pdev->dev;
    const char *label;
}

/**
 * @brief This function is called, when the module is loaded into the kernel
 */
static int __init ili9341_init(void) {
	printk("Hello, Kernel!\n");
	return 0;
}

/**
 * @brief This function is called, when the module is removed from the kernel
 */
static void __exit ili9341_exit(void) {
	printk("Goodbye, Kernel\n");
}

module_init(ili9341_init);
module_exit(ili9341_exit);

