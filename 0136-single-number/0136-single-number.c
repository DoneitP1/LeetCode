int singleNumber(int* a, int n) {
    int r=0;
    for(int i=0;i<n;i++){
        r^=a[i];
    }
    return r;
    
    
}