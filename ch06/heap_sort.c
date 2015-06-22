#include "heap.h"
#include "heap_sort.h"

void heapSort(double testData[], int testDataNum){
    double swapTemp;
    int i;
    Heap_t sortHeap = buildMaxHeap(testData, testDataNum);
    for (i = testDataNum - 1; i>=1; i--){
        //swap the largest element of the heap to the position
        swapTemp = sortHeap.pData[0];
        sortHeap.pData[0] = sortHeap.pData[i];
        sortHeap.pData[i] = swapTemp;
        //shrink the heap and max-heapfiy again
        (sortHeap.heapSize)--;
        maxHeapify(&sortHeap, 0);
    }
}
