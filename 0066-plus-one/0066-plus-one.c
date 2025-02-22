int* plusOne(int* digits, int digitsSize, int* returnSize) {
    int zeroStartNext = digitsSize - 1;
    while (zeroStartNext >= 0 && digits[zeroStartNext] == 9) --zeroStartNext;
    
    if (zeroStartNext < 0)
    {
        *returnSize = digitsSize + 1;
        int *out = (int*)calloc(sizeof(int), *returnSize);
        out[0] = 1;
        return out;
    }

    *returnSize = digitsSize;
    int *out = (int*)calloc(sizeof(int), *returnSize);
    for (int i = 0; i < zeroStartNext; ++i)
    {
        out[i] = digits[i]; 
    }
    out[zeroStartNext] = digits[zeroStartNext] + 1; 
    return out;
}