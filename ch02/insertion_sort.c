#include <stdlib.h>
#include <stdio.h>
#include "include/sort_data_helper.h"


/*
    Insertion Sort
 */
void insertionSort(double data[], size_t n){
    int i, j;
    double value;
    //begin from the 2nd element
    for (i=1; i<n; i++){
        value = data[i];
        j=i-1;
        while (j>=0 && (data[j] >= value)){
            //shift the element one position behind
            data[j+1] = data[j];
            j--;
        }
        data[j+1] = value;
    }
}

/* test */
int main(int argc, char *argv[]){
    double *testData;
    size_t n;
    prepareData(&testData, &n);
    //dumpData(testData, n);
    insertionSort(testData, n);
    //dumpData(testData, n);
    if (checkData(testData, n)){
        printf("Sort correct!\n");
    }
    else {
        printf("Sort incorrect!\n");
    }
    free(testData);
    return 0;
}
