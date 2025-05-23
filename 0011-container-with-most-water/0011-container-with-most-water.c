int maxArea(int* arr, int N){
    int max = 0, i = 0, j = N - 1;
    while(j > i){
        int test = arr[i];
        if(test > arr[j]) test = arr[j];
        test *= (j - i);
        if(max < test) max = test;
        if(arr[i] < arr[j]) i++ ;
        else j--;
    }
    return max;
}