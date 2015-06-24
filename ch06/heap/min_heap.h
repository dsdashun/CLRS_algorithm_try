#ifndef _MIN_HEAP_H
#define _MIN_HEAP_H

#include "heap.h"

Heap_t buildMinHeap(HeapElem_t *pData, int length);
void minHeapify(Heap_t *pHeap, int i);

HeapElem_t *getMin(Heap_t *pHeap);
HeapElem_t extractMin(Heap_t *pHeap);
void insertMinHeapElem(Heap_t *pHeap, HeapElem_t elem);
void decreaseMinHeapKeyValue(Heap_t *pHeap, int i, double newValue);
void removeMinHeapElem(Heap_t *pHeap, int i);

#endif
