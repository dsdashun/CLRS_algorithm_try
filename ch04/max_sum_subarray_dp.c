#include <stdlib.h>
#include <stdio.h>
#include "include/prepare_data_helper.h"

typedef struct {
    int left;
    int right;
    double sumValue;
} subArrayInfo_t;

//double testArray[] = {13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7};
double *testArray;

subArrayInfo_t computeMaxSumSubarray(int n){
    subArrayInfo_t maxSumSubarrayInfo;
    int i = 0;
    maxSumSubarrayInfo.left = 0;
    maxSumSubarrayInfo.right = 0;
    maxSumSubarrayInfo.sumValue = testArray[0];
    double maxSuffixSum = testArray[0];
    int maxSuffixStartIndex = 0;
    for (i = 1; i<n; i++){
        //update the max suffix sum
        maxSuffixSum += testArray[i];
        if (testArray[i] > maxSuffixSum){
            maxSuffixStartIndex = i;
            maxSuffixSum = testArray[i];
        }
        //update the max sum array by compare
        if (maxSuffixSum > maxSumSubarrayInfo.sumValue){
            maxSumSubarrayInfo.left = maxSuffixStartIndex;
            maxSumSubarrayInfo.right = i;
            maxSumSubarrayInfo.sumValue = maxSuffixSum;
        }
    }
    return maxSumSubarrayInfo;
}

int main(int argc, char *argv[]){
    size_t n;
    prepareDoubleArray(&testArray, &n);
    subArrayInfo_t subarrayInfo = computeMaxSumSubarray(n);
    printf("max sum subarray: %d, %d, %f\n", subarrayInfo.left, subarrayInfo.right, subarrayInfo.sumValue);
    free(testArray);
    return 0;
}
