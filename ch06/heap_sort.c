#include <stdlib.h>
#include "heap/max_heap.h"
#include "heap_sort.h"
#include "include/set_element.h"

void heapSort(double testData[], int testDataNum){
    int i;
    SetElem_t *pHeapData = generateElemArrayByKeyList_Double(testData, testDataNum);
    Heap_t sortHeap = buildMaxHeap(pHeapData, testDataNum);
    for (i = testDataNum - 1; i>=1; i--){
        //swap the largest element of the heap to the position
        testData[i] = sortHeap.pData[0].key.doubleKey;
        sortHeap.pData[0] = sortHeap.pData[i];
        //shrink the heap and max-heapfiy again
        (sortHeap.heapSize)--;
        maxHeapify(&sortHeap, 0);
    }
    testData[i] = sortHeap.pData[0].key.doubleKey;
    free(pHeapData);
}
