int hammingWeight(int n) {
    int count=1;
    while(n!=1){
        if(n%2==1){
            count++;
            n=n/2;
        }
        else{
            n=n/2;
        }
    }
    return count;
}