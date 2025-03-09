#!/bin/sh

rmmod raspberrypi_gpiomem
rmmod led_chardev
insmod ./led_chardev.ko
