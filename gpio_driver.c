#include <linux/module.h>
#include <linux/gpio/consumer.h>
#include <linux/platform_device.h>

static struct gpio_desc *led_gpio;

static int __init gpio_driver_init(void) {
    int ret;
    led_gpio = gpiod_get(NULL, "gpio21", GPIOD_OUT_LOW);
    if (IS_ERR(led_gpio)) {
        printk(KERN_ERR "GPIO request failed: %ld\n", PTR_ERR(led_gpio));
        return PTR_ERR(led_gpio);
    }
    gpiod_set_value(led_gpio, 1); // Turn LED on
    printk(KERN_INFO "GPIO Driver Loaded for Raspberry Pi\n");
    return 0;
}

static void __exit gpio_driver_exit(void) {
    gpiod_set_value(led_gpio, 0); // Turn LED off
    gpiod_put(led_gpio);
    printk(KERN_INFO "GPIO Driver Unloaded\n");
}

module_init(gpio_driver_init);
module_exit(gpio_driver_exit);
MODULE_LICENSE("GPL");
MODULE_AUTHOR("Amarnath B R<digitallyamar@gmail.com>");
MODULE_DESCRIPTION("Raspberry Pi GPIO Driver for LED Control");