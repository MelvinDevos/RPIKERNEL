# RPIKERNEL
Kernel module that controls GPIO


sudo rmmod main
make
sudo insmod main.ko gpio_array=17,27 level_array=1,0 toggle_array=8,5
dmesg