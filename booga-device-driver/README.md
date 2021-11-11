##Project 3 Device Driver
*Author: Royal Pathak
*Class: CS 552 Operating Systems

##Overview

Implementing a simple character driver called booga that supports the open, read and write and close operations with four minor numbers: 0, 1, 2, and 3. We use VMware-based CentOS 7 (64 bit) for testing on a Linux machine with root privilege. The device files are: /dev/booga0, /dev/booga1, /dev/booga2, /dev/booga3.

##Manifest

booga.c -> Main class created that contains functionalities for booga device driver.

booga.h -> C header file for the booga.c 

booga-test1.sh -> Shell script file to test

booga-test2.sh -> Shellscript file to test 

booga_load-> for loading driver to Linux

booga_unload-> for unloading driver to Linux

Makefile-> bulid the code such as make/clean

##Building the project

<pre>[cs453@localhost booga-device-driver]$ make clean
/bin/rm -f test-booga test-booga.o
/bin/rm -f .booga* booga.o booga.mod.c booga.mod.o booga.ko Modules.* modules.*
/bin/rm -fr .tmp_versions/
[cs453@localhost booga-device-driver]$ make
make -C /lib/modules/`uname -r`/build M=`pwd` modules
make[1]: Entering directory `/usr/src/kernels/3.10.0-957.el7.x86_64&apos;
  CC [M]  /home/cs453/Documents/booga-device-driver/booga.o
  Building modules, stage 2.
  MODPOST 1 modules
  CC      /home/cs453/Documents/booga-device-driver/booga.mod.o
  LD [M]  /home/cs453/Documents/booga-device-driver/booga.ko
make[1]: Leaving directory `/usr/src/kernels/3.10.0-957.el7.x86_64&apos;
cc    -c -o test-booga.o test-booga.c
cc  -o test-booga test-booga.o
[cs453@localhost booga-device-driver]$ 
</pre>

##Features and usage

I have copied the output i received when i run in CentOS 7 64-bit as instructed.

Here is the copy of output i received: 

For first test shellscript, i have just copied some part of output since its too long

[cs453@localhost booga-device-driver]$ sudo ./booga-test1.sh
[sudo] password for cs453: 
 booga returned 0 characters

 booga returned 1 characters
n
 booga returned 2 characters
bo
 booga returned 10 characters
neka! maka
 booga returned 10 characters
googoo! ga
 booga returned 100 characters
booga! booga! booga! booga! booga! booga! booga! booga! booga! booga! booga! booga! booga! booga! bo
 booga returned 1000 characters
neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka
 booga returned 10000 characters
wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! woog
 booga returned 100000 characters
a! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka
 booga returned 200000 characters




Attempting to write to booga device
Wrote 1000 bytes.
Attempting to write to booga device
Wrote 1000 bytes.
Attempting to write to booga device
Wrote 1000 bytes.
Attempting to write to booga device
./booga-test1.sh: line 19: 16439 Terminated              ./test-booga 3 1000 w
 booga returned 0 characters
1
 booga returned 1 characters
2
 booga returned 2 characters
3
 booga returned 10 characters
11
 booga returned 10 characters
11
 booga returned 100 characters
101
 booga returned 1000 characters
1001
 booga returned 10000 characters
10001
 booga returned 100000 characters
100001
 booga returned 200000 characters
200001


<pre>[cs453@localhost booga-device-driver]$ sudo ./booga-test2.sh

[sudo] password for cs453: 

bytes read = 0 
bytes written = 0 
number of opens:
 /dev/booga0 = 0 times
 /dev/booga1 = 0 times
 /dev/booga2 = 0 times
 /dev/booga3 = 0 times
strings output:
 booga! booga!   = 0 times
 googoo! gaagaa! = 0 times
 wooga! wooga!   = 0 times
 neka! maka!     = 0 times

 booga returned 100 characters
wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wo
 booga returned 100 characters
wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wo
 booga returned 100 characters
wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wooga! wo
Attempting to write to booga device
 booga returned 100 characters
neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka! maka! neka
Attempting to write to booga device
Wrote 100 bytes.
Attempting to write to booga device
Wrote 100 bytes.
./booga-test2.sh: line 18: 16903 Terminated              ./test-booga 3 100 w
Attempting to write to booga device
Wrote 100 bytes.

bytes read = 400 
bytes written = 400 
number of opens:
 /dev/booga0 = 2 times
 /dev/booga1 = 2 times
 /dev/booga2 = 2 times
 /dev/booga3 = 2 times
strings output:
 booga! booga!   = 0 times
 googoo! gaagaa! = 0 times
 wooga! wooga!   = 3 times
 neka! maka!     = 1 times

[cs453@localhost booga-device-driver]$ 
</pre>



##Testing

During the final run, I run the both testscripts booga-test1.sh, and booga-test2.sh and got output as expected; run like a charm.

##Known Bugs

There are no bugs as per my knowledge. NO BUGS during make / running scripts/ testing.

##Reflection and Self Assessment

I started early to make sure I was on the right track. The kernel-level C programming was different, and I had to understand it through an example project given by the professor. Also, the class discussion was very fruitful as I got ideas from classmates about how to approach the task.

The main problem I was stuck in was I was not getting the device driver statistics correct. Later, I realized that I had not used semaphores properly. Also, I appreciate Dr. Jidong's office hours for debugging my issues. 

Overall, it was a pretty challenging project for me as I come from a Mathematics background. But, it was worth understanding the concept of the device driver through the project. 




##Sources used

For most of the help, i have refer to example project and Dr. Jidong office hours to debug my issues.




