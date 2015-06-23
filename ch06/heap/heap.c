#include <stdio.h>
#include "heap.h"

int isValidIndex(Heap_t *pHeap, int index){
    return (index < pHeap->heapSize) ? 1 : 0;
}
int nonLeafNodeNum(Heap_t *pHeap){
    return pHeap->heapSize / 2;
}

