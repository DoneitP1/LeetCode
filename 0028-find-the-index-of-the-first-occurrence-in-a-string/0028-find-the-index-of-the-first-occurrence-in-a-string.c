int strStr(char* haystack, char* needle) {
    if (needle[0] == '\0') {
        return 0;
    }
    
    int hay_len = strlen(haystack);
    int need_len = strlen(needle);
    if (need_len > hay_len) {
        return -1;
    }
     for (int i = 0; i <= hay_len - need_len; i++) {  
        int j = 0;
        while (j < need_len && haystack[i + j] == needle[j]) {
            j++;
        }
        if (j == need_len) {  
            return i;
        }
    }

    return -1; 
}