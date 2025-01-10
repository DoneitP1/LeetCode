void countFrequency(const char* word, int frequency[26]) {
    memset(frequency, 0, 26 * sizeof(int));
    while (*word) {
        frequency[*word - 'a']++;
        word++;
    }
}

bool isUniversal(int wordFrequency[26], int maxFrequency[26]) {
    for (int i = 0; i < 26; i++) {
        if (wordFrequency[i] < maxFrequency[i]) {
            return false;
        }
    }
    return true;
}

char** wordSubsets(char** words1, int words1Size, char** words2, int words2Size, int* returnSize) {
    int maxFrequency[26] = {0};
    int tempFrequency[26];


    for (int i = 0; i < words2Size; i++) {
        countFrequency(words2[i], tempFrequency);
        for (int j = 0; j < 26; j++) {
            if (tempFrequency[j] > maxFrequency[j]) {
                maxFrequency[j] = tempFrequency[j];
            }
        }
    }


    char** result = (char**)malloc(words1Size * sizeof(char*));
    *returnSize = 0;
    for (int i = 0; i < words1Size; i++) {
        countFrequency(words1[i], tempFrequency);
        if (isUniversal(tempFrequency, maxFrequency)) {
            result[*returnSize] = words1[i];
            (*returnSize)++;
        }
    }

    return result;
}