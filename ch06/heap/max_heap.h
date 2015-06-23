#ifndef _MAX_HEAP_H
#define _MAX_HEAP_H

#include "heap.h"

Heap_t buildMaxHeap(HeapElem_t *pData, int length);
void maxHeapify(Heap_t *pHeap, int i);
void maxHeapify_NonRecursive(Heap_t *pHeap, int i);

HeapElem_t getMax(Heap_t *pHeap);
HeapElem_t extractMax(Heap_t *pHeap);
void insertMaxHeapElem(Heap_t *pHeap, HeapElem_t elem);
void increaseMaxHeapKeyValue(Heap_t *pHeap, int i, double newKeyValue);
void removeMaxHeapElem(Heap_t *pHeap, int i);

#endif
