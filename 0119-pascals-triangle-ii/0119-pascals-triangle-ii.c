/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getRow(int rowIndex, int* returnSize) {
    int* rowIndexth = (int*)malloc((rowIndex + 1) * sizeof(int));
    *returnSize = rowIndex + 1;

    rowIndexth [0] = 1;

   for(int j = 1; j <= rowIndex; j++) {  
    rowIndexth[j] = (long long)rowIndexth[j - 1] * (rowIndex - j + 1) / j;

          
    }

    return rowIndexth;
    
    
    


   
    
}