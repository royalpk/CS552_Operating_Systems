#ifndef __LAB_H
#define __LAB_H

#ifdef __cplusplus
extern "C" {
#endif

#define TRUE 1
#define FALSE 0

// function prototypes
void serial_mergesort(int A[], int p, int r);
void merge(int A[], int p, int q, int r);
void insertion_sort(int A[], int p, int r);
void parallel_mergesort(int A[], int p, int r, int noOfThread);
void *mythread(void *arg);

#ifdef __cplusplus
}
#endif
#endif //__LAB_H
