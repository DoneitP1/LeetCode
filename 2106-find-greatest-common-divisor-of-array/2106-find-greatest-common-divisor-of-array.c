int findGCD(int* nums, int numsSize){
  int max=0, min =1001;
  for (int i=0; i<numsSize; i++){
    if (nums[i]>max){
      max=nums[i];
    }
    if (nums[i]<min){
      min=nums[i];
    }
  }
  int temp;
  while(true){
    temp = max % min;
    if (temp == 0){
      break;
    }else{
      max = min;
      min = temp;
    }
  }
  return min;
}