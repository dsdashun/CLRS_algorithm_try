#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "heap/min_heap.h"
#include "include/prepare_data_helper.h"

void merge_k_sorted_arrays(double *arrayList[], int lengthList[], int k, double *resultArray){
    typedef struct {
        double *pData;
        int currentIndex;
        int arrayNum;
    } ArrayInfo_t;
    SetElem_t *arrayHeadData, *pMinElem;
    double minValue;
    int i;
    Heap_t arrayHeadHeap;
    ArrayInfo_t *arrayInfoList, *pRootArrayInfo;

    arrayHeadData = calloc(k, sizeof(SetElem_t));
    arrayInfoList = calloc(k, sizeof(ArrayInfo_t));

    for (i=0; i<k; i++){
        arrayInfoList[i].pData = arrayList[i];
        arrayInfoList[i].currentIndex = 0;
        arrayInfoList[i].arrayNum = lengthList[i];

        arrayHeadData[i].key.doubleKey = arrayList[i][0];
        arrayHeadData[i].pHandle = arrayInfoList+i;
    }
    arrayHeadHeap = buildMinHeap(arrayHeadData, k);
    i = 0;
    while (arrayHeadHeap.heapSize > 0){
        pMinElem = getMin(&arrayHeadHeap);
        resultArray[i] = pMinElem->key.doubleKey;
        pRootArrayInfo = (ArrayInfo_t *)(pMinElem->pHandle);

        (pRootArrayInfo->pData)++;
        (pRootArrayInfo->currentIndex)++;

        if (pRootArrayInfo->currentIndex >= pRootArrayInfo->arrayNum){
            //the array is empty, remove it
            removeMinHeapElem(&arrayHeadHeap, 0);
        }
        else {
            //extract the next value
            pMinElem->key.doubleKey = pRootArrayInfo->pData[0];
            minHeapify(&arrayHeadHeap, 0);
        }
        i++;
    }
}

int main(int argc, char *argv[]){
    double array1[] = {1,3,5,7,9};
    double array2[] = {2,4,6,8,10,12,14,16};
    double array3[] = {11,13,15};
    double *arrayList[3] = {array1, array2, array3};
    int lengthList[3] = {5, 8, 3};
    double resultArray[16];

    merge_k_sorted_arrays(arrayList, lengthList, 3, resultArray);
    dumpDoubleArray(resultArray, 16);
    return 0;
}
