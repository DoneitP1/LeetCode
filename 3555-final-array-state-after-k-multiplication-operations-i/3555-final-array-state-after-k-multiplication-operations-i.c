#include <stdlib.h>

int* getFinalState(int* nums, int numsSize, int k, int multiplier, int* returnSize) {
    int* result = (int*)malloc(numsSize * sizeof(int));
    for (int i = 0; i < numsSize; i++) {
        result[i] = nums[i];  
    }
    for (int op = 0; op < k; op++) {
        int minIndex = 0;
        for (int i = 1; i < numsSize; i++) {
            if (result[i] < result[minIndex]) {
                minIndex = i;
            }
        }
        result[minIndex] *= multiplier;
    }

    *returnSize = numsSize;  
    return result;           
}