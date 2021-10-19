## Project 2 Thread Safe Library

* Author: Royal Pathak
* Class: CS552 Operating Systems

## Overview

Solving Producer Consumer problems with the implementation of thread-safe version of an existing list library.

Also created ThreadsafeBoundedList.c file in the wrapper-library subfolder to complete the implementation of the thread-safe list library.

Furthermore, Multi-queue version was enhanced which allows user to specify the number of queues as the first command line argument.

## Manifest

pc.c -> Main class created to test single thread bounded list.

pc-mq.c -> Enhanced version extension of pc.c for multi-queue size bounded in round robin fashioned.

test-pc.sh -> Shellscript file to test pc.c

test-pc-mq.sh -> Shellscript file to test pc-mq.c

ThreadsafeBoundedList.h -> C header file that contains function declarations for all functions contained for multiple queue pc.c

ThreadsafeBoundedList.c -> C file for creating and implementing functions declarations mentioned in header file.

Makefile-> bulid the code such as make/clean

## Building the project



[royalpathak@onyxnode08 thread-safe-library]$ export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:./list/lib:./lib

[royalpathak@onyxnode08 thread-safe-library]$ make

cd wrapper-library/; make

make[1]: Entering directory '/home/ROYALPATHAK/CS-552---Operating-Systems/thread-safe-library/wrapper-library'

gcc -Wall -MMD -g -O   -O -fPIC -I..//list/include   -c -o ThreadsafeBoundedList.o ThreadsafeBoundedList.c

ld -shared -o libthreadsafe-mylib.so  ThreadsafeBoundedList.o 

ar  rcv libthreadsafe-mylib.a ThreadsafeBoundedList.o 

a - ThreadsafeBoundedList.o

ranlib libthreadsafe-mylib.a

make[1]: Leaving directory '/home/ROYALPATHAK/CS-552---Operating-Systems/thread-safe-library/wrapper-library'

cd wrapper-library/; make install

make[1]: Entering directory '/home/ROYALPATHAK/CS-552---Operating-Systems/thread-safe-library/wrapper-library'

install --mode=444 -C ThreadsafeBoundedList.h ..//include

install --mode=444 -C libthreadsafe-mylib.so ..//lib

install --mode=444 -C libthreadsafe-mylib.a ..//lib

make[1]: Leaving directory '/home/ROYALPATHAK/CS-552---Operating-Systems/thread-safe-library/wrapper-library'

gcc -g -O -Wall -MMD  -Iinclude/ -I./list/include/   -c -o pc.o pc.c

gcc -g -O -Wall -MMD  -Iinclude/ -I./list/include/   -c -o Item.o Item.c

gcc -g -O -Wall -MMD  -Iinclude/ -I./list/include/ -o pc pc.o Item.o  -lpthread -Llib/ -lthreadsafe-mylib -L./list/lib/ -lmylib 

gcc -g -O -Wall -MMD  -Iinclude/ -I./list/include/   -c -o pc-mq.o pc-mq.c

gcc -g -O -Wall -MMD  -Iinclude/ -I./list/include/ -o pc-mq pc-mq.o Item.o  -lpthread -Llib/ -lthreadsafe-mylib -L./list/lib/ -lmylib 

## Features and usage

I have copied the output i received when i run in onyx server.

Here is the copy of output i received:

------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

For single queue version, i have just copied some part of the output:


[royalpathak@onyxnode08 thread-safe-library]$ ./test-pc.sh 

1 producers 1 consumers 10 items 10 pool size

 #items produced = 10   #items consumed = 10 

1 producers 2 consumers 10 items 10 pool size

 #items produced = 10   #items consumed = 10 

1 producers 4 consumers 10 items 10 pool size

 #items produced = 10   #items consumed = 10 

1 producers 8 consumers 10 items 10 pool size

 #items produced = 10   #items consumed = 10 

2 producers 1 consumers 20 items 10 pool size

 #items produced = 20   #items consumed = 20 

2 producers 2 consumers 20 items 10 pool size

 #items produced = 20   #items consumed = 20 

-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


For  multiple queues version

[royalpathak@onyxnode08 thread-safe-library]$ ./test-pc-mq.sh 

5 Number of queues 5 producers 5 consumers 10000 items 10 pool size

 #items produced = 10000   #items consumed = 10000 

5 Number of queues 5 producers 10 consumers 10000 items 10 pool size

 #items produced = 10000   #items consumed = 10000 

5 Number of queues 10 producers 5 consumers 20000 items 10 pool size

 #items produced = 20000   #items consumed = 20000 

5 Number of queues 10 producers 10 consumers 20000 items 10 pool size

 #items produced = 20000   #items consumed = 20000 

5 Number of queues 5 producers 5 consumers 10000 items 10 pool size

 #items produced = 10000   #items consumed = 10000 

5 Number of queues 5 producers 10 consumers 10000 items 10 pool size

 #items produced = 10000   #items consumed = 10000 

5 Number of queues 10 producers 5 consumers 20000 items 10 pool size

 #items produced = 20000   #items consumed = 20000 

5 Number of queues 10 producers 10 consumers 20000 items 10 pool size
 #items produced = 20000   #items consumed = 20000 
5 Number of queues 5 producers 5 consumers 10000 items 100 pool size

 #items produced = 10000   #items consumed = 10000 

5 Number of queues 5 producers 10 consumers 10000 items 100 pool size

 #items produced = 10000   #items consumed = 10000 

5 Number of queues 10 producers 5 consumers 20000 items 100 pool size

 #items produced = 20000   #items consumed = 20000 

5 Number of queues 10 producers 10 consumers 20000 items 100 pool size

 #items produced = 20000   #items consumed = 20000 

5 Number of queues 5 producers 5 consumers 10000 items 100 pool size

 #items produced = 10000   #items consumed = 10000 

5 Number of queues 5 producers 10 consumers 10000 items 100 pool size

 #items produced = 10000   #items consumed = 10000 

5 Number of queues 10 producers 5 consumers 20000 items 100 pool size

 #items produced = 20000   #items consumed = 20000 

5 Number of queues 10 producers 10 consumers 20000 items 100 pool size

 #items produced = 20000   #items consumed = 20000 

5 Number of queues 5 producers 5 consumers 10000 items 300 pool size

 #items produced = 10000   #items consumed = 10000 

5 Number of queues 5 producers 10 consumers 10000 items 300 pool size

 #items produced = 10000   #items consumed = 10000 

5 Number of queues 10 producers 5 consumers 20000 items 300 pool size

 #items produced = 20000   #items consumed = 20000
 
5 Number of queues 10 producers 10 consumers 20000 items 300 pool size

 #items produced = 20000   #items consumed = 20000 

5 Number of queues 5 producers 5 consumers 10000 items 300 pool size

 #items produced = 10000   #items consumed = 10000 

5 Number of queues 5 producers 10 consumers 10000 items 300 pool size

 #items produced = 10000   #items consumed = 10000 

5 Number of queues 10 producers 5 consumers 20000 items 300 pool size

 #items produced = 20000   #items consumed = 20000 

5 Number of queues 10 producers 10 consumers 20000 items 300 pool size

 #items produced = 20000   #items consumed = 20000 

10 Number of queues 5 producers 5 consumers 10000 items 10 pool size

 #items produced = 10000   #items consumed = 10000 

10 Number of queues 5 producers 10 consumers 10000 items 10 pool size

 #items produced = 10000   #items consumed = 10000 

10 Number of queues 10 producers 5 consumers 20000 items 10 pool size

 #items produced = 20000   #items consumed = 20000 

10 Number of queues 10 producers 10 consumers 20000 items 10 pool size

 #items produced = 20000   #items consumed = 20000 

10 Number of queues 5 producers 5 consumers 10000 items 10 pool size

 #items produced = 10000   #items consumed = 10000 

10 Number of queues 5 producers 10 consumers 10000 items 10 pool size

 #items produced = 10000   #items consumed = 10000 

10 Number of queues 10 producers 5 consumers 20000 items 10 pool size

 #items produced = 20000   #items consumed = 20000 

10 Number of queues 10 producers 10 consumers 20000 items 10 pool size

 #items produced = 20000   #items consumed = 20000 

10 Number of queues 5 producers 5 consumers 10000 items 100 pool size

 #items produced = 10000   #items consumed = 10000 

10 Number of queues 5 producers 10 consumers 10000 items 100 pool size

 #items produced = 10000   #items consumed = 10000 

10 Number of queues 10 producers 5 consumers 20000 items 100 pool size

 #items produced = 20000   #items consumed = 20000 

10 Number of queues 10 producers 10 consumers 20000 items 100 pool size

 #items produced = 20000   #items consumed = 20000 

10 Number of queues 5 producers 5 consumers 10000 items 100 pool size

 #items produced = 10000   #items consumed = 10000 

10 Number of queues 5 producers 10 consumers 10000 items 100 pool size

 #items produced = 10000   #items consumed = 10000 

10 Number of queues 10 producers 5 consumers 20000 items 100 pool size

 #items produced = 20000   #items consumed = 20000 

10 Number of queues 10 producers 10 consumers 20000 items 100 pool size

 #items produced = 20000   #items consumed = 20000 

10 Number of queues 5 producers 5 consumers 10000 items 300 pool size

 #items produced = 10000   #items consumed = 10000 

10 Number of queues 5 producers 10 consumers 10000 items 300 pool size

 #items produced = 10000   #items consumed = 10000 

10 Number of queues 10 producers 5 consumers 20000 items 300 pool size

 #items produced = 20000   #items consumed = 20000 

10 Number of queues 10 producers 10 consumers 20000 items 300 pool size

 #items produced = 20000   #items consumed = 20000 

10 Number of queues 5 producers 5 consumers 10000 items 300 pool size

 #items produced = 10000   #items consumed = 10000 

10 Number of queues 5 producers 10 consumers 10000 items 300 pool size

 #items produced = 10000   #items consumed = 10000 

10 Number of queues 10 producers 5 consumers 20000 items 300 pool size

 #items produced = 20000   #items consumed = 20000 

10 Number of queues 10 producers 10 consumers 20000 items 300 pool size

 #items produced = 20000   #items consumed = 20000 


## Testing

During the final run, I  run the testscripts for both versions of mainfile, test-pc.sh,and test-pc-mq.sh in onyx server . It will working smoothly like charm. 


## Known Bugs

There are no bugs as per my knowledge. NO BUGS during makerun / running scripts/ testing.



## Reflection and Self Assessment

Coming from Mathematics background for long time made it hard to recollect my C programming skills. 

I got segmentation fault many times but i debug and fixed them.
 
I would like to appreciate Dr.Jidong for his office hours to help me with the the debug.

Similarly, i had received race condition in my code while running test shellscripts. I solved them through adding mutex locks which i missed.

Overall, the project was really informative and there was lot of learning curve in the project.  


## Sources used

For most of the help, i have refer to Dr. Jidong office hours but the following links sources also helped me alot to understand. 

http://www.eg.bucknell.edu/~xmeng/Course/CS4334/Example/Pthread/producer-consumer.c

https://stackoverflow.com/questions/40855584/c-producer-consumer-using-pthreads

https://www.cc.gatech.edu/classes/AY2010/cs4210_fall/code/ProducerConsumer.c

https://medium.com/@sohamshah456/producer-consumer-programming-with-c-d0d47b8f103f

