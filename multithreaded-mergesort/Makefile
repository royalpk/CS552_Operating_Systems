CC = gcc
CFLAGS = -Wall -Wextra -Wpointer-arith -Wstrict-prototypes -std=gnu89 -fPIC -MMD -MP
LDFLAGS = -shared
LIBS=-lpthread
all: libmylab.so mytests

#This builds a shared library.
libmylab.so: lab.o
	$(CC) $(CFLAGS) $(LDFLAGS) $^ -o $@

#This builds an executable it depends on the library
mytests: mytests.o libmylab.so
	$(CC) $(CFLAGS) $< -L. -Wl,-rpath=. -lmylab $(LIBS) -o $@

.PHONY: clean
clean:
	$(RM) *.o *.d *.gcno *.gcda *.gcov libmylab.so mytests

-include *.d
