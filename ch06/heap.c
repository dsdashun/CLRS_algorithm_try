#include <stdio.h>
#include "heap.h"

//swap the largest node, 
//and return the largest index among index, left child, right child
static int getLargestAmongChild(Heap_t *pHeap, int i);
static int getSmallestAmongChild(Heap_t *pHeap, int i);

int isValidIndex(Heap_t *pHeap, int index){
    return (index < pHeap->heapSize) ? 1 : 0;
}
int nonLeafNodeNum(Heap_t *pHeap){
    return pHeap->heapSize / 2;
}

Heap_t buildMaxHeap(double *pData, int length){
    int i;
    Heap_t resultHeap;
    resultHeap.pData = pData;
    resultHeap.heapSize = length;
    for (i = nonLeafNodeNum(&resultHeap); i>=0; i--){
        maxHeapify(&resultHeap, i);
        //maxHeapify_NonRecursive(&resultHeap, i);
    }
    return resultHeap;
}

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

void maxHeapify(Heap_t *pHeap, int i){
    int largestIndex;
    double swapTemp;
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

void maxHeapify_NonRecursive(Heap_t *pHeap, int i){
    int largestIndex = i;
    int nextLargestIndex;
    double swapTemp;
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
        (pHeap->pData[i] < pHeap->pData[LEFT_CHILD(i)])
    ){
        largestIndex = LEFT_CHILD(i);
    }
    else {
        largestIndex = i;
    }
    if (isValidIndex(pHeap, RIGHT_CHILD(i)) && 
        pHeap->pData[largestIndex] < pHeap->pData[RIGHT_CHILD(i)]
    ){
        largestIndex = RIGHT_CHILD(i);
    }
    return largestIndex;
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
