## Project 4 Memory Manager Buddy System

* Author: Royal Pathak
* Class: CS552 Operating Systems

## Overview
Implementation of our own memory management by replacing malloc/free with own memory management scheme or memory manager using buddy algorithm. We initially allocate 512 MB of allocate block of memory and manage the memory return by allocation command (sbrk()) using memory management functions.

## Manifest

buddy.c -> Main class  file created for the implementation for malloc and free
 
buddy.h -> C header file for buddy.c file.

malloc-test.c -> C file used for testing buddy malloc.

buddy-test.c ->C file used for testing buddy program.

buddy-unit-test.c -> C file that contains unit test for buddy program.

Makefile -> build the code such as make/clean.


## Building the project

I built the project on onyxnode and it is working with no compilation warning.

For your references, check screenshot/Building


## Features and usage
This program has various feature and usage. I have run the code in onyx and taken screenshot to show various features.

Malloc and free 1 byte works. This screenshot is in Screenshot/freeonebyte.

The allocation beyond maximum fails gracefully. This screenshot is in Screenshot/failsgraxefully.

I did perform stablity test by running buddy-test with at least 10M iterations without crashing. This screenshot is in Screenshot/stablitytest.

For other functional test, i used various other parameters, and i was working like a charm.

I also implemented mergesort integration via interposing. The screenshot can be found in Screenshot/interposemergesort.The screenshot shows how both parallel and serial merge sert is integrated via interposing.

I have also done browser integration via interposing.The screenshot can be found in Screenshot/browserintegration.

My buddy system  outperforms the default malloc which is also provided in the screenshot.The screenshot can be found in Screenshot/outperformdefmalloc

## Testing

I have performed testing with both buddy-preload, and buddy-non-preload.The various testing includes stablity testing which works perfectly
for 10M iteration without crashing.


## Known Bugs

There are no bugs to my knowledge.

Initially i faced lot of segfault but i debugged it and fix them before submitting and my final code commit,

## Reflection and Self Assessment

This is the most challenging assignment. Initially it was really hard to understand buddy_malloc(),but drawing the picture helped me to get the clear understanding. Similarly, i received seg fault and it took me lot of time to debug it. Just to realise that i missed adding the mutex lock to the critical
section. Furthermore, i got lot of issue while interposing the mergesort and browser. I realise i need to make a thread safe to interpose.

Last but not the least, in class discussion were very helpful and learning curve on the assignment is high.

## Sources used
For most of the help i got was from in class discussion. 

