bool isIsomorphic(char* s, char* t) {
    char map_s[128] = {0};
    char map_t[128] = {0};
    int len = strlen(s);
    for (int i = 0; i < len; ++i) {
        if (map_s[s[i]] != map_t[t[i]])
            return false;
        map_s[s[i]] = i + 1;
        map_t[t[i]] = i + 1;
    }
    return true;
}