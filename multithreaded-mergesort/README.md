## Project 1 Multithreaded Merge Sort 

* Author: Royal Pathak
* Class: CS552 Operating Systems

## Overview
Implementation of multithreaded mergesort using pthread library from the given single threaded version of mergesort. 
The analysis is also done to understand efficiency and effectiveness using number of threads and speedups, and  comparision of single thread with multiple thread on various elements respectively.
 


## Manifest

lab.c -> updated with new parallel_mergesort function which takes the parameter elements, first element of array, last element of array, and number of threads.

lab.h ->updated with new function protypes created for parallel mergesort implementation

mytest.c ->updated with parallel_mergesort call to make sure it include timing results for both the serial and parallel versions of merge sort.

runval.sh -> check valgrind test.

Makefile -> bulid the code such as make/clean

analysis.xlsx -> this file contain all the data used for the analysis of efficiency and effectiveness.

speedup.pdf-> pdf file containing the implementation analysis of Efficiency and Effectiveness of multithreading in case of mergesort.

## Building the project


[royalpathak@onyxnode08 multithreaded-mergesort]$ make clean

rm -f *.o *.d *.gcno *.gcda *.gcov libmylab.so mytests

[royalpathak@onyxnode08 multithreaded-mergesort]$ make

gcc -Wall -Wextra -Wpointer-arith -Wstrict-prototypes -std=gnu89 -fPIC -MMD -MP   -c -o lab.o lab.c

gcc -Wall -Wextra -Wpointer-arith -Wstrict-prototypes -std=gnu89 -fPIC -MMD -MP -shared lab.o -o libmylab.so

gcc -Wall -Wextra -Wpointer-arith -Wstrict-prototypes -std=gnu89 -fPIC -MMD -MP   -c -o mytests.o mytests.c

gcc -Wall -Wextra -Wpointer-arith -Wstrict-prototypes -std=gnu89 -fPIC -MMD -MP mytests.o -L. -Wl,-rpath=. -lmylab -lpthread -o mytests

[royalpathak@onyxnode08 multithreaded-mergesort]$ 



## Features and usage

I have copied the code run in onyx server.we have command line arguments, element and number of threads.It gives us the sorting time done in parallel and serial respectively.

Here is the copy of output i received:

[royalpathak@onyxnode08 multithreaded-mergesort]$ ./mytests 100000000 7

Parallel sorting 100000000 elements took 5.55 seconds.

Serial sorting 100000000 elements took 25.22 seconds.


## Testing

I have run elements in the range from 1,000,000 to 100,000,000, incrementing by 1M each time each time with 5 threads for all test cases.

Also I ran tests cases for 1-8 threads with 100 million elements.

## Known Bugs

There are no bugs as per my knowledge.

Similarly, I have tested the Valgrind check. It has reported no memory leaks or read/write errors in the code.

Here is the copy of output i received :

[royalpathak@onyxnode08 multithreaded-mergesort]$ runval.sh 

==62287== Memcheck, a memory error detector

==62287== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.

==62287== Using Valgrind-3.16.0 and LibVEX; rerun with -h for copyright info

==62287== Command: ./mytests 10000 1

==62287== 

Parallel sorting 10000 elements took 0.02 seconds.

Serial sorting 10000 elements took 0.02 seconds.

==62287== 

==62287== HEAP SUMMARY:

==62287==     in use at exit: 0 bytes in 0 blocks

==62287==   total heap usage: 257 allocs, 257 frees, 641,032 bytes allocated

==62287== 

==62287== All heap blocks were freed -- no leaks are possible

==62287== 

==62287== For lists of detected and suppressed errors, rerun with: -s

==62287== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

[royalpathak@onyxnode08 multithreaded-mergesort]$ 


## Reflection and Self Assessment

I am from Mathematics / Data Science background for long time, so it took time to recollect my C programming skills.Similarly,I would like to appreciate the Book References Chapter 27,Interlude: Thread API which have wonderful explaination for the pthread library and sample code in the book example helped a lot.Furthermore, i came over stackoverflow and blogs which helped me during the development.


## Sources used
Mostly,I have referred to chapter 27:Interlude: Thread API. Also the following sources helps me on my way:

https://stackoverflow.com/questions/48889007/multithreaded-merge-sort-programming

https://stackoverflow.com/questions/43808114/implementation-of-merge-sort-using-threads-and-fork

https://malithjayaweera.com/2019/02/parallel-merge-sort/

https://pages.cs.wisc.edu/~remzi/OSTEP/threads-api.pdf 


