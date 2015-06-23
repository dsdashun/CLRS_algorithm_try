#include <stdio.h>
#include "include/prepare_data_helper.h"
#include "include/sort_data_helper.h"
#include "heap_sort.h"

//double testData[] = {4, 1, 3, 2, 16, 9, 10, 14, 8, 7};
//int testDataNum = 10;
double *testData;

int main(int argc, char *argv[]){
    //dumpDoubleArray(testData, testDataNum);
    size_t testDataNum;
    prepareDoubleArray(&testData, &testDataNum);
    heapSort(testData, (int)testDataNum);
    //dumpDoubleArray(testData, testDataNum);
    if (checkData(testData, testDataNum)){
        printf("Sort correct!\n");
    }
    else {
        printf("Sort incorrect!\n");
    }
}
