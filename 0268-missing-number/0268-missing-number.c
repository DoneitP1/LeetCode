int missingNumber(int* nums, int numsSize) {
    int sum = 0,i=0,tot=numsSize;
    for(i = 0;i<numsSize;i++){
        sum += nums[i];
        tot += i;
    }
    return tot-sum;
}