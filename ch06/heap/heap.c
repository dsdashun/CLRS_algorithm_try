#include <float.h>
#include <stdio.h>
#include <stdlib.h>
#include "heap.h"

int isValidIndex(Heap_t *pHeap, int index){
    return (index < pHeap->heapSize) ? 1 : 0;
}
int nonLeafNodeNum(Heap_t *pHeap){
    return pHeap->heapSize / 2;
}

void dumpHeap(Heap_t *pHeap){
    size_t i;
    printf("Heap size: %d, data: [ ", pHeap->heapSize);
    for (i=0; i<pHeap->heapSize; i++){
        printf("%f, ", pHeap->pData[i].key.doubleKey);
    }
    printf(" ]\n");
}
