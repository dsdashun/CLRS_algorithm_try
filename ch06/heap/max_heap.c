#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <float.h>
#include "max_heap.h"

//swap the largest node,
//and return the largest index among index, left child, right child
static int getLargestAmongChild(Heap_t *pHeap, int i);

Heap_t buildMaxHeap(SetElem_t *pData, int length){
    int i;
    Heap_t resultHeap;
    resultHeap.pData = pData;
    resultHeap.heapSize = length;
    resultHeap.length = length;
    for (i = nonLeafNodeNum(&resultHeap); i>=0; i--){
        maxHeapify(&resultHeap, i);
        //maxHeapify_NonRecursive(&resultHeap, i);
    }
    return resultHeap;
}

void maxHeapify(Heap_t *pHeap, int i){
    int largestIndex;
    SetElem_t swapTemp;
    //get the largest one amone the node and its child nodes
    largestIndex = getLargestAmongChild(pHeap, i);
    //if i is not the largest, swap, and recursively call max heapify
    if (largestIndex != i){
        swapTemp = pHeap->pData[i];
        pHeap->pData[i] = pHeap->pData[largestIndex];
        pHeap->pData[largestIndex] = swapTemp;
        maxHeapify(pHeap, largestIndex);
    }
}

void maxHeapify_NonRecursive(Heap_t *pHeap, int i){
    int largestIndex = i;
    int nextLargestIndex;
    SetElem_t swapTemp;
    while ((nextLargestIndex = getLargestAmongChild(pHeap, largestIndex)) != largestIndex){
        swapTemp = pHeap->pData[largestIndex];
        pHeap->pData[largestIndex] = pHeap->pData[nextLargestIndex];
        pHeap->pData[nextLargestIndex] = swapTemp;
        largestIndex = nextLargestIndex;
    }
}

int getLargestAmongChild(Heap_t *pHeap, int i){
    int largestIndex = i;
    if (isValidIndex(pHeap, LEFT_CHILD(i)) &&
        (pHeap->pData[i].key.doubleKey < pHeap->pData[LEFT_CHILD(i)].key.doubleKey)
    ){
        largestIndex = LEFT_CHILD(i);
    }
    else {
        largestIndex = i;
    }
    if (isValidIndex(pHeap, RIGHT_CHILD(i)) &&
        pHeap->pData[largestIndex].key.doubleKey < pHeap->pData[RIGHT_CHILD(i)].key.doubleKey
    ){
        largestIndex = RIGHT_CHILD(i);
    }
    return largestIndex;
}

SetElem_t *getMax(Heap_t *pHeap){
    if (pHeap->heapSize <= 0){
        return NULL;
    }
    return pHeap->pData;
}

SetElem_t extractMax(Heap_t *pHeap){
    if (pHeap->heapSize <= 0){
        return errorElem;
    }
    SetElem_t maxData = pHeap->pData[0];
    pHeap->pData[0] = pHeap->pData[pHeap->heapSize - 1];
    (pHeap->heapSize)--;
    maxHeapify(pHeap, 0);
    return maxData;
}

void increaseMaxHeapKeyValue(Heap_t *pHeap, int i, double newValue){
    SetElem_t newElem;
    if (i >= pHeap->heapSize){
        return;
    }
    if (newValue <= pHeap->pData[i].key.doubleKey){
        fprintf(stderr, "new value should larger than old value");
        return;
    }
    newElem = pHeap->pData[i];
    newElem.key.doubleKey = newValue;
/*
    //original method
    double swapTemp;
    pHeap->pData[i] = newValue;
    while (i>0 && pHeap->pData[PARENT(i)] < pHeap->pData[i]){
        swapTemp = pHeap->pData[i];
        pHeap->pData[i] = pHeap->pData[PARENT(i)];
        pHeap->pData[PARENT(i)] = swapTemp;
    }
*/
    //improved method
    while (i>0 && pHeap->pData[PARENT(i)].key.doubleKey < newValue){
        pHeap->pData[i] = pHeap->pData[PARENT(i)];
        i = PARENT(i);
    }
    pHeap->pData[i] = newElem;
}

void insertMaxHeapElem(Heap_t *pHeap, SetElem_t elem){
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
    pHeap->pData[pHeap->heapSize - 1].key.doubleKey = -DBL_MAX;
    increaseMaxHeapKeyValue(pHeap, pHeap->heapSize - 1, elem.key.doubleKey);
}

void removeMaxHeapElem(Heap_t *pHeap, int i){
    if (i >= pHeap->heapSize){
        return;
    }
    pHeap->pData[i] = pHeap->pData[pHeap->heapSize - 1];
    (pHeap->heapSize)--;
    maxHeapify(pHeap, i);
}
