int isVowel(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

int isValid(char* s) {
    int len = strlen(s);
    return isVowel(s[0]) && isVowel(s[len - 1]) ? 1 : 0;
}

int* vowelStrings(char** words, int wordsSize, int** queries, int queriesSize, int* queriesColSize, int* returnSize) {
    int* prefix = (int*)calloc(wordsSize + 1, sizeof(int));
    for (int i = 1; i <= wordsSize; i++) {
        prefix[i] = prefix[i - 1] + isValid(words[i - 1]);
    }
    int* res = (int*)malloc(queriesSize * sizeof(int));
    for (int i = 0; i < queriesSize; i++) {
        res[i] = prefix[queries[i][1] + 1] - prefix[queries[i][0]];
    }
    free(prefix);
    *returnSize = queriesSize;
    return res;
}