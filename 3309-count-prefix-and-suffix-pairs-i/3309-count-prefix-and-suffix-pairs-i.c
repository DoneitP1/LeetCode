int countPrefixSuffixPairs(char** words, int wordsSize) {
    int count = 0;
    for (int i = 0; i < wordsSize - 1; i++) {
        for (int j = i + 1; j < wordsSize; j++) {
            int a = strlen(words[i])-1, b = strlen(words[j])-1;
            if (a <= b) {
                for (int x = 0; x <= a; x++) {
                    if (words[i][x] != words[j][x] || words[i][a - x] != words[j][b - x]) {
                        count--;
                        break;
                    }
                }
                count++;
            }
        }
    }
    return count;
}