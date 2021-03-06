#include <stdio.h>
#include <stdlib.h>
#include "include/prepare_data_helper.h"
#include "include/set_element.h"
#include "max_heap.h"
#include "min_heap.h"
#include "heap.h"

int main(int argc, char *argv[]){
    double testData[] = {4, 1, 3, 2, 16, 9, 10, 14, 8, 7};
    double testData2[] = {4, 1, 3, 2, 16, 9, 10, 14, 8, 7};
    int testDataNum = 10;
    double maxValue;
    Heap_t aMaxHeap, aMinHeap;
    SetElem_t *pHeapData, *pHeapData2, newElem;

    dumpDoubleArray(testData, testDataNum);
    pHeapData = generateElemArrayByKeyList_Double(testData, testDataNum);
    aMaxHeap = buildMaxHeap(pHeapData, testDataNum);
    dumpHeap(&aMaxHeap);
    newElem.key.doubleKey=13;
    insertMaxHeapElem(&aMaxHeap, newElem);
    dumpHeap(&aMaxHeap);
    maxValue = extractMax(&aMaxHeap).key.doubleKey;
    printf("Max data in heap is: %f\n", maxValue);
    dumpHeap(&aMaxHeap);
    removeMaxHeapElem(&aMaxHeap, 3);
    dumpHeap(&aMaxHeap);

    pHeapData2 = generateElemArrayByKeyList_Double(testData2, testDataNum);
    aMinHeap = buildMinHeap(pHeapData2, testDataNum);
    dumpHeap(&aMinHeap);
    newElem.key.doubleKey=2.5;
    insertMinHeapElem(&aMinHeap, newElem);
    dumpHeap(&aMinHeap);
    extractMin(&aMinHeap);
    dumpHeap(&aMinHeap);
    removeMinHeapElem(&aMinHeap, 3);
    dumpHeap(&aMinHeap);

    return 0;
}
