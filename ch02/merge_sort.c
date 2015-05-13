#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "include/sort_data_helper.h"

#define BIG_DOUBLE 99999999.9999

//two parts, the first part is leftIndex ~ middleIndex-1
//the second part is middleIndex ~ rightIndex
//for example left index = 0, right index = 1, length = 2, middle index = 0 + 2/2 = 1
static void combine(double dataArray[], size_t leftIndex, size_t middleIndex, size_t rightIndex){
    double *leftDataArray, *rightDataArray;
    size_t leftLength = middleIndex - leftIndex;
    size_t rightLength = rightIndex - middleIndex + 1;
    size_t l, r, i;
    //the last +1 for sentinal value
    if ((leftDataArray = calloc(leftLength + 1, sizeof(double))) == NULL){
        perror("calloc failed");
        exit(1);
    }
    if ((rightDataArray = calloc(rightLength + 1, sizeof(double))) == NULL){
        perror("calloc right array failed");
        exit(1);
    }
    memmove(leftDataArray, dataArray+leftIndex, leftLength * sizeof(double));
    memmove(rightDataArray, dataArray+middleIndex, rightLength * sizeof(double));
    leftDataArray[leftLength] = BIG_DOUBLE;
    rightDataArray[rightLength] = BIG_DOUBLE;
    l = 0;
    r = 0;
    i = leftIndex;
    while (i<=rightIndex){
        if (leftDataArray[l] < rightDataArray[r]){
            dataArray[i] = leftDataArray[l];
            l++;
        }
        else{
            dataArray[i] = rightDataArray[r];
            r++;
        }
        i++;
    }
    free(leftDataArray);
    free(rightDataArray);
}

void mergeSort(double dataArray[], size_t leftIndex, size_t rightIndex){
    size_t n = rightIndex - leftIndex + 1;
    size_t middleIndex = leftIndex + n / 2;
    if (n <= 1){
        return;
    }
    mergeSort(dataArray, leftIndex, middleIndex-1);
    mergeSort(dataArray, middleIndex, rightIndex);
    combine(dataArray, leftIndex, middleIndex, rightIndex);
}

int main(int argc, char *argv[]){
    double *testData;
    size_t n;
    prepareData(&testData, &n);
    mergeSort(testData, 0, n-1);
    if (checkData(testData, n)){
        printf("Sort correct!\n");
    }
    else {
        printf("Sort incorrect!\n");
    }
    free(testData);
    return 0;
}
