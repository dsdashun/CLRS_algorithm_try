#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include "min_heap.h"

static int getSmallestAmongChild(Heap_t *pHeap, int i);

Heap_t buildMinHeap(HeapElem_t *pData, int length){
    int i;
    Heap_t resultHeap;
    resultHeap.pData = pData;
    resultHeap.heapSize = length;
    for (i = nonLeafNodeNum(&resultHeap); i>=0; i--){
        minHeapify(&resultHeap, i);
    }
    return resultHeap;
}

void minHeapify(Heap_t *pHeap, int i){
    int smallestIndex;
    HeapElem_t swapTemp;
    //get the smallest one amone the node and its child nodes
    smallestIndex = getSmallestAmongChild(pHeap, i);
    //if i is not the smallest, swap, and recursively call max heapify
    if (smallestIndex != i){
        swapTemp = pHeap->pData[i];
        pHeap->pData[i] = pHeap->pData[smallestIndex];
        pHeap->pData[smallestIndex] = swapTemp;
        minHeapify(pHeap, smallestIndex);
    }
}

int getSmallestAmongChild(Heap_t *pHeap, int i){
    int smallestIndex = i;
    if (isValidIndex(pHeap, LEFT_CHILD(i)) &&
        (pHeap->pData[i].key > pHeap->pData[LEFT_CHILD(i)].key)
    ){
        smallestIndex = LEFT_CHILD(i);
    }
    else {
        smallestIndex = i;
    }
    if (isValidIndex(pHeap, RIGHT_CHILD(i)) &&
        pHeap->pData[smallestIndex].key > pHeap->pData[RIGHT_CHILD(i)].key
    ){
        smallestIndex = RIGHT_CHILD(i);
    }
    return smallestIndex;
}

HeapElem_t getMin(Heap_t *pHeap){
    if (pHeap->heapSize <= 0){
        return errorElem;
    }
    return pHeap->pData[0];
}

HeapElem_t extractMin(Heap_t *pHeap){
    if (pHeap->heapSize <= 0){
        return errorElem;
    }
    HeapElem_t minData = pHeap->pData[0];
    pHeap->pData[0] = pHeap->pData[pHeap->heapSize - 1];
    (pHeap->heapSize)--;
    minHeapify(pHeap, 0);
    return minData;
}

void insertMinHeapElem(Heap_t *pHeap, HeapElem_t elem){
    HeapElem_t *pNewData;
    if (pHeap->heapSize == pHeap->length){
        //allocate more memory
        if ((pNewData = calloc(pHeap->length + 128, sizeof(HeapElem_t))) == NULL){
            fprintf(stderr, "alloc memory failed\n");
            return;
        }
        memcpy(pNewData, pHeap->pData, pHeap->heapSize * sizeof(HeapElem_t));
        pHeap->pData = pNewData;
        pHeap->length += 128;
    }
    (pHeap->heapSize)++;
    pHeap->pData[pHeap->heapSize - 1] = elem;
    pHeap->pData[pHeap->heapSize - 1].key = DBL_MAX;
    decreaseMinHeapKeyValue(pHeap, pHeap->heapSize - 1, elem.key);
}

void decreaseMinHeapKeyValue(Heap_t *pHeap, int i, double newValue){
    HeapElem_t newElem;
    if (i >= pHeap->heapSize){
        return;
    }
    if (newValue >= pHeap->pData[i].key){
        fprintf(stderr, "new value should smaller than old value");
        return;
    }
    newElem = pHeap->pData[i];
    newElem.key = newValue;
    //improved method
    while (i>0 && pHeap->pData[PARENT(i)].key > newValue){
        pHeap->pData[i] = pHeap->pData[PARENT(i)];
        i = PARENT(i);
    }
    pHeap->pData[i] = newElem;
}

void removeMinHeapElem(Heap_t *pHeap, int i){
    if (i >= pHeap->heapSize){
        return;
    }
    pHeap->pData[i] = pHeap->pData[pHeap->heapSize - 1];
    (pHeap->heapSize)--;
    minHeapify(pHeap, i);
}
