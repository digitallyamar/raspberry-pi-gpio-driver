# Raspberry Pi GPIO Driver

This repository contains a Linux kernel module for controlling GPIO pins on Raspberry Pi 3, 4, and 5, including support for the Pi 5’s RP1 chip. It accompanies the article [How to Write a Raspberry Pi GPIO Driver: Ultimate Guide for Pi 3/4/5](https://www.giraffai.com/raspberry-pi/raspberry-pi-gpio-driver), which provides a step-by-step guide with debugging tips and device tree setup.

## Features
- Controls GPIO 21 (LED example) using the `gpiod` API.
- Includes a device tree overlay for Raspberry Pi 5 (RP1 chip).
- Compatible with Raspberry Pi OS (2025, kernel 6.6).

## Files
- `gpio_driver.c`: Kernel module to toggle an LED on GPIO 21.
- `led-gpio.dts`: Device tree overlay for Pi 5 GPIO.
- `Makefile`: For compiling the driver.

## Usage
1. Clone the repo: `git clone https://github.com/digitallyamar/raspberry-pi-gpio-driver.git`
2. Compile: `make`
3. Load: `sudo insmod gpio_driver.ko`
4. See the full tutorial at [GiraffAI](https://giraffai.com/raspberry-pi-gpio-driver).

## Author
Amarnath Revanna, Linux kernel developer with 15+ years of BSP experience, including the [CAIF driver](https://android.googlesource.com/kernel/mediatek/+/android-mediatek-sprout-3.4-kitkat-mr2/drivers/net/caif/caif_shmcore.c).

## License
GPL
