#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

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

void dumpData(double data[], size_t n){
    size_t i;
    for (i=0; i<n; i++){
        printf("%f, ", data[i]);
    }
    printf("\n");
}

int checkData(double data[], size_t n){
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
            maxSize << 1;
            if ((*pDataArray = realloc(*pDataArray,maxSize)) == NULL){
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
    return 0;
}
