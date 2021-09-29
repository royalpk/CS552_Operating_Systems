## Project 1 Multithreaded Merge Sort 

* Author: Royal Pathak
* Class: CS552 Operating Systems

## Overview
 Implementation of multithreaded mergesort using pthread library from the given single threaded version of mergesort. The analysis is also done based on number of threads and speedups, comparision of single thread with multiple thread on various elements.
 


## Manifest

lab.c -> updated with new parallel_mergesort function which takes the parameter elements, first element of array, last element of array, and number of threads.

lab.h ->updated with new function protypes created for parallel mergesort implementation

mytest.c ->updated with parallel_mergesort call commenting serial_mergesort.

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

[royalpathak@onyxnode08 multithreaded-mergesort]$ ./mytests 100000000 6

Parallel sorting 100000000 elements took 5.63 seconds.

Serial sorting 100000000 elements took 11.17 seconds.

[royalpathak@onyxnode08 multithreaded-mergesort]$ 


## Testing

I have run elements in the range from 1,000,000 to 100,000,000, incrementing by 1M each time each time with 5 threads for all test cases.

Also I ran tests cases for 1-8 threads with 100 million elements.

## Known Bugs

There are no bugs as per my knowledge.
Similarly, I have tested the Valgrind check. It has reported no memory leaks or read/write errors in the code.  
Here is the copy of output i received :

[royalpathak@onyxnode08 multithreaded-mergesort]$ runval.sh

==88799== HEAP SUMMARY:

==88799==     in use at exit: 0 bytes in 0 blocks

==88799==   total heap usage: 383 allocs, 383 frees, 881,028 bytes allocated

==88799==
 
==88799== All heap blocks were freed -- no leaks are possible

==88799== 

==88799== For lists of detected and suppressed errors, rerun with: -s

==88799== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)



## Reflection and Self Assessment

I am from Mathematics / Data Science background for long time, so it took time to recollect my C programming skills.Similarly,I would like to appreciate the Book References Chapter 27,Interlude: Thread API which have wonderful explaination for the pthread library and sample code in the book example helped a lot.Furthermore, i came over stackoverflow and blogs which helped me during the development.


## Sources used
Mostly,I have referred to chapter 27:Interlude: Thread API. Also the following sources helps me on my way:

https://stackoverflow.com/questions/48889007/multithreaded-merge-sort-programming

https://stackoverflow.com/questions/43808114/implementation-of-merge-sort-using-threads-and-fork

https://malithjayaweera.com/2019/02/parallel-merge-sort/

https://pages.cs.wisc.edu/~remzi/OSTEP/threads-api.pdf 


