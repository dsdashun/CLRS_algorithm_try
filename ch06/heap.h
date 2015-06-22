#ifndef _HEAP_H
#define _HEAP_H

#define LEFT_CHILD(i) 2 * (i) + 1
#define RIGHT_CHILD(i) 2 * (i) + 2
#define PARENT(i) ((i) - 1) / 2

typedef struct {
    double *pData;
    int heapSize;
} Heap_t;

Heap_t buildMaxHeap(double *pData, int length);
Heap_t buildMinHeap(double *pData, int length);
void maxHeapify(Heap_t *pHeap, int i);
void maxHeapify_NonRecursive(Heap_t *pHeap, int i);
void minHeapify(Heap_t *pHeap, int i);
int isValidIndex(Heap_t *pHeap, int index);
int nonLeafNodeNum(Heap_t *pHeap);

#endif
