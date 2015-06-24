#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include "min_heap.h"

static int getSmallestAmongChild(Heap_t *pHeap, int i);

Heap_t buildMinHeap(SetElem_t *pData, int length){
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
    SetElem_t swapTemp;
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
        (pHeap->pData[i].key.doubleKey > pHeap->pData[LEFT_CHILD(i)].key.doubleKey)
    ){
        smallestIndex = LEFT_CHILD(i);
    }
    else {
        smallestIndex = i;
    }
    if (isValidIndex(pHeap, RIGHT_CHILD(i)) &&
        pHeap->pData[smallestIndex].key.doubleKey > pHeap->pData[RIGHT_CHILD(i)].key.doubleKey
    ){
        smallestIndex = RIGHT_CHILD(i);
    }
    return smallestIndex;
}

SetElem_t *getMin(Heap_t *pHeap){
    if (pHeap->heapSize <= 0){
        return NULL;
    }
    return pHeap->pData;
}

SetElem_t extractMin(Heap_t *pHeap){
    if (pHeap->heapSize <= 0){
        return errorElem;
    }
    SetElem_t minData = pHeap->pData[0];
    pHeap->pData[0] = pHeap->pData[pHeap->heapSize - 1];
    (pHeap->heapSize)--;
    minHeapify(pHeap, 0);
    return minData;
}

void insertMinHeapElem(Heap_t *pHeap, SetElem_t elem){
    SetElem_t *pNewData;
    if (pHeap->heapSize == pHeap->length){
        //allocate more memory
        if ((pNewData = calloc(pHeap->length + 128, sizeof(SetElem_t))) == NULL){
            fprintf(stderr, "alloc memory failed\n");
            return;
        }
        memcpy(pNewData, pHeap->pData, pHeap->heapSize * sizeof(SetElem_t));
        pHeap->pData = pNewData;
        pHeap->length += 128;
    }
    (pHeap->heapSize)++;
    pHeap->pData[pHeap->heapSize - 1] = elem;
    pHeap->pData[pHeap->heapSize - 1].key.doubleKey = DBL_MAX;
    decreaseMinHeapKeyValue(pHeap, pHeap->heapSize - 1, elem.key.doubleKey);
}

void decreaseMinHeapKeyValue(Heap_t *pHeap, int i, double newValue){
    SetElem_t newElem;
    if (i >= pHeap->heapSize){
        return;
    }
    if (newValue >= pHeap->pData[i].key.doubleKey){
        fprintf(stderr, "new value should smaller than old value");
        return;
    }
    newElem = pHeap->pData[i];
    newElem.key.doubleKey = newValue;
    //improved method
    while (i>0 && pHeap->pData[PARENT(i)].key.doubleKey > newValue){
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
