char * convert(char * s, int numRows){
    int size = strlen(s) + 5;
    if (numRows == 1 || size-5 <= numRows ) return s;
    
    char **zigzag = (char**)calloc(numRows * size, sizeof(char));
    for(int i = 0; i < numRows; i++) *(zigzag + i) = (char*) calloc(size, sizeof(char));
    
    int direction = -1, level = 0, i = 0; 
    while( s[i] != '\0' ){
        strncat(zigzag[level], &s[i++], 1);
        if ( level % (numRows-1) == 0 ) direction *= -1;
        level += direction;
    }
    strcpy(s, "");
    for(int i = 0; i < numRows; i++)strcat(s, zigzag[i]);
    
    for(int i = 0; i < numRows; i++){
        free(*(zigzag + i));
    }
    free(zigzag);
    return s;
}