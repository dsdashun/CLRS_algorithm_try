#ifndef _MAX_HEAP_H
#define _MAX_HEAP_H

#include "heap.h"

Heap_t buildMaxHeap(double *pData, int length);
void maxHeapify(Heap_t *pHeap, int i);
void maxHeapify_NonRecursive(Heap_t *pHeap, int i);

double getMax(Heap_t *pHeap);
double extractMax(Heap_t *pHeap);
void insertMaxHeapElem(Heap_t *pHeap, double value);
void increaseValue(Heap_t *pHeap, int i, double newValue);
void removeMaxHeapElem(Heap_t *pHeap, int i);

#endif
