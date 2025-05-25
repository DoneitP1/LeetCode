bool isMatch(char* s, char* p) {
    if(s == NULL && p == NULL) return true;
    if(*p == '\0') return *s == '\0';

    if(*(p + 1) == '*') {
 
        return((*s != '\0' && (*s == *p || *p == '.')) && isMatch(s + 1, p)) || isMatch(s, p + 2); 

    }else{
    
        return (*s != '\0' && (*s == *p || *p == '.')) && isMatch(s + 1, p + 1);
    }
}