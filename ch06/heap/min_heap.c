#include <float.h>
#include <string.h>
#include <stdio.h>
#include "min_heap.h"

static int getSmallestAmongChild(Heap_t *pHeap, int i);

Heap_t buildMinHeap(double *pData, int length){
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
    double swapTemp;
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
        (pHeap->pData[i] > pHeap->pData[LEFT_CHILD(i)])
    ){
        smallestIndex = LEFT_CHILD(i);
    }
    else {
        smallestIndex = i;
    }
    if (isValidIndex(pHeap, RIGHT_CHILD(i)) &&
        pHeap->pData[smallestIndex] > pHeap->pData[RIGHT_CHILD(i)]
    ){
        smallestIndex = RIGHT_CHILD(i);
    }
    return smallestIndex;
}

double getMin(Heap_t *pHeap){
    if (pHeap->heapSize <= 0){
        return -DBL_MAX;
    }
    return pHeap->pData[0];
}

double extractMin(Heap_t *pHeap){
    if (pHeap->heapSize <= 0){
        return -DBL_MAX;
    }
    double minData = pHeap->pData[0];
    pHeap->pData[0] = pHeap->pData[pHeap->heapSize - 1];
    (pHeap->heapSize)--;
    minHeapify(pHeap, 0);
    return minData;
}

void insertMinHeapElem(Heap_t *pHeap, double value){
    double *pNewData;
    if (pHeap->heapSize == pHeap->length){
        //allocate more memory
        if ((pNewData = calloc(pHeap->length + 128, sizeof(double))) == NULL){
            fprintf(stderr, "alloc memory failed\n");
            return;
        }
        memcpy(pNewData, pHeap->pData, pHeap->heapSize * sizeof(double));
        pHeap->pData = pNewData;
        pHeap->length += 128;
    }
    (pHeap->heapSize)++;
    pHeap->pData[pHeap->heapSize - 1] = DBL_MAX;
    decreaseMinHeapValue(pHeap, pHeap->heapSize - 1, value);
}

void decreaseMinHeapValue(Heap_t *pHeap, int i, double newValue){
    double swapTemp;
    if (i >= pHeap->heapSize){
        return;
    }
    if (newValue >= pHeap->pData[i]){
        fprintf(stderr, "new value should smaller than old value");
        return;
    }
    //improved method
    while (i>0 && pHeap->pData[PARENT(i)] > newValue){
        pHeap->pData[i] = pHeap->pData[PARENT(i)];
        i = PARENT(i);
    }
    pHeap->pData[i] = newValue;
}

void removeMinHeapElem(Heap_t *pHeap, int i){
    if (i >= pHeap->heapSize){
        return;
    }
    pHeap->pData[i] = pHeap->pData[pHeap->heapSize - 1];
    (pHeap->heapSize)--;
    minHeapify(pHeap, i);
}
