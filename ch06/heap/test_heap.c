#include <stdio.h>
#include <stdlib.h>
#include "include/prepare_data_helper.h"
#include "max_heap.h"
#include "min_heap.h"

int main(int argc, char *argv[]){
    double testData[] = {4, 1, 3, 2, 16, 9, 10, 14, 8, 7};
    double testData2[] = {4, 1, 3, 2, 16, 9, 10, 14, 8, 7};
    int testDataNum = 10;
    double maxValue;
    Heap_t aMaxHeap, aMinHeap;

    dumpDoubleArray(testData, testDataNum);
    aMaxHeap = buildMaxHeap(testData, testDataNum);
    dumpDoubleArray(aMaxHeap.pData, aMaxHeap.heapSize);
    insertMaxHeapElem(&aMaxHeap, 13);
    dumpDoubleArray(aMaxHeap.pData, aMaxHeap.heapSize);
    maxValue = extractMax(&aMaxHeap);
    printf("Max data in heap is: %f\n", maxValue);
    dumpDoubleArray(aMaxHeap.pData, aMaxHeap.heapSize);
    removeMaxHeapElem(&aMaxHeap, 3);
    dumpDoubleArray(aMaxHeap.pData, aMaxHeap.heapSize);

    aMinHeap = buildMinHeap(testData2, testDataNum);
    dumpDoubleArray(aMinHeap.pData, aMinHeap.heapSize);
    insertMinHeapElem(&aMinHeap, 2.5);
    dumpDoubleArray(aMinHeap.pData, aMinHeap.heapSize);
    extractMin(&aMinHeap);
    dumpDoubleArray(aMinHeap.pData, aMinHeap.heapSize);
    removeMinHeapElem(&aMinHeap, 3);
    dumpDoubleArray(aMinHeap.pData, aMinHeap.heapSize);

    return 0;
}
