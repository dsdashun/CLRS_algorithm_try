#ifndef _MIN_HEAP_H
#define _MIN_HEAP_H

#include "heap.h"

Heap_t buildMinHeap(double *pData, int length);
void minHeapify(Heap_t *pHeap, int i);

double getMin(Heap_t *pHeap);
double extractMin(Heap_t *pHeap);
void insertMinHeapElem(Heap_t *pHeap, double value);
void decreaseMinHeapValue(Heap_t *pHeap, int i, double newValue);
void removeMinHeapElem(Heap_t *pHeap, int i);

#endif
