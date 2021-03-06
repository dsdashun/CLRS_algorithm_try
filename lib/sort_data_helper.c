#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include "include/sort_data_helper.h"

void dumpData(double data[], size_t n){
    size_t i;
    for (i=0; i<n; i++){
        printf("%f, ", data[i]);
    }
    printf("\n");
}

unsigned char checkData(double data[], size_t n){
    size_t i;
    for (i=1; i<n; i++){
        if (data[i] < data[i-1]){
            return 0;
        }
    }
    return 1;
}

int prepareData(double **pDataArray, size_t *pSize){
    char inputBuffer[64];
    size_t n = 0;
    size_t maxSize = 128;
    if ((*pDataArray = calloc(maxSize, sizeof(double))) == NULL){
        perror("alloc memory failed");
        exit(-1);
    }
    while (fgets(inputBuffer, 64, stdin)){
        if (n>=maxSize){
            /* double the max size*/
            maxSize = maxSize << 1;
            if ((*pDataArray = realloc(*pDataArray,maxSize * sizeof(double))) == NULL){
                perror("re-alloc memory failed");
                exit(-1);
            }
        }
        (*pDataArray)[n] = atof(inputBuffer);
        n++;
    }
    *pSize = n;
    return 1;
}

