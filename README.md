# RPIKERNEL
Kernel module that controls GPIO


sudo rmmod main
make
sudo insmod main.ko gpio_array=5,12 level_array=1,0 toggle_array=0,5
dmesg