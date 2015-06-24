#ifndef _HEAP_H
#define _HEAP_H

#include "include/set_element.h"

#define LEFT_CHILD(i) 2 * (i) + 1
#define RIGHT_CHILD(i) 2 * (i) + 2
#define PARENT(i) ((i) - 1) / 2

typedef struct {
    SetElem_t *pData;
    int heapSize;
    int length;
} Heap_t;

int isValidIndex(Heap_t *pHeap, int index);
int nonLeafNodeNum(Heap_t *pHeap);
void dumpHeap(Heap_t *pHeap);

#endif
