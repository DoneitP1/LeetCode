int removeElement(int* nums, int numsSize, int val) {

    int k=0;
    for(int i=0;i<numsSize;i++){
        if(nums[i]!=val){
            nums[k]=nums[i];
            k++;
        }
       
    }
    
    for(int i=1;i<k;i++){
        for(int j=0;j<k-i;j++){
            if(nums[j]>nums[j+1]){
                int t=nums[j];
                nums[j]=nums[j+1];
                nums[j+1]=t;
            }
        }
    }
    return  k;
}