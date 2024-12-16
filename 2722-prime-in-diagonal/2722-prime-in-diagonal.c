bool isPrime(int num){
    if(num==1){
        return false;
    }
    if(num==2){
        return true;
    }
    for(int i=2;i<num/2;i++){
        if(num%i==0){
            return false;
        }
    }
    return true;
}
int diagonalPrime(int** nums, int numsSize, int* numsColSize){
    int prime=0;
    for(int i=0;i<numsSize;i++){
        int sam=nums[i][i];
        if(sam>prime&&isPrime(sam)){
                prime=sam;
        }
    }
    for(int i=0;i<numsSize;i++){
        int sam=nums[i][numsSize-i-1];
        if(sam>prime&&isPrime(sam)){
            prime=sam;
        }
    }
    return prime;
}