#include <stdlib.h>
#include <stdio.h>
#include "include/prepare_data_helper.h"

double *testArray;
typedef struct {
    int left;
    int right;
    double sumValue;
} subArrayInfo_t;

void dumpSubArrayInfo(subArrayInfo_t subarrayInfo){
    printf("max sum subarray: %d, %d, %f\n", subarrayInfo.left, subarrayInfo.right, subarrayInfo.sumValue);
}

subArrayInfo_t computeCrossBoundMaxSumSubarray(int lowIndex, int highIndex, int midIndex){
    int i;
    double maxSumValue = -999999999999999999;
    double sumValue = 0.0;
    int maxSumIndex = 0;
    subArrayInfo_t crossBoundSubarrayInfo;
    for (i=midIndex; i>=lowIndex; i--){
        sumValue += testArray[i];
        if (sumValue > maxSumValue){
            maxSumValue = sumValue;
            maxSumIndex = i;
        }
    }
    crossBoundSubarrayInfo.left = maxSumIndex;
    //compute the right side
    sumValue = maxSumValue;
    for (i=midIndex+1; i<=highIndex; i++){
        sumValue += testArray[i];
        if (sumValue > maxSumValue){
            maxSumValue = sumValue;
            maxSumIndex = i;
        }
    }
    crossBoundSubarrayInfo.right = maxSumIndex;
    crossBoundSubarrayInfo.sumValue = maxSumValue;
    return crossBoundSubarrayInfo;
}

subArrayInfo_t computeMaxSumSubarray(int lowIndex, int highIndex){
    subArrayInfo_t maxSumSubarrayInfo, maxSumSubarrayInfo_left, maxSumSubarrayInfo_right, maxSumSubarrayInfo_cross;
    int midIndex;
    if (lowIndex == highIndex){
        maxSumSubarrayInfo.left = lowIndex;
        maxSumSubarrayInfo.right = highIndex;
        maxSumSubarrayInfo.sumValue = testArray[lowIndex];
        return maxSumSubarrayInfo;
    }
    else {
        midIndex = (lowIndex + highIndex) / 2;
        maxSumSubarrayInfo_left = computeMaxSumSubarray(lowIndex, midIndex);
        maxSumSubarrayInfo_right = computeMaxSumSubarray(midIndex + 1, highIndex);
        maxSumSubarrayInfo_cross = computeCrossBoundMaxSumSubarray(lowIndex, highIndex, midIndex);
        if (maxSumSubarrayInfo_left.sumValue >= maxSumSubarrayInfo_right.sumValue &&
            maxSumSubarrayInfo_left.sumValue >= maxSumSubarrayInfo_cross.sumValue){
            return maxSumSubarrayInfo_left;
        }
        else if (maxSumSubarrayInfo_right.sumValue >= maxSumSubarrayInfo_left.sumValue &&
            maxSumSubarrayInfo_right.sumValue >= maxSumSubarrayInfo_cross.sumValue){
            return maxSumSubarrayInfo_right;
        }
        else {
            return maxSumSubarrayInfo_cross;
        }
    }
}

int main(int argc, char *argv[]){
    size_t n;
    prepareDoubleArray(&testArray, &n);
    subArrayInfo_t subarrayInfo = computeMaxSumSubarray(0, (int)n-1);
    printf("max sum subarray: %d, %d, %f\n", subarrayInfo.left, subarrayInfo.right, subarrayInfo.sumValue);
    free(testArray);
    return 0;
}
