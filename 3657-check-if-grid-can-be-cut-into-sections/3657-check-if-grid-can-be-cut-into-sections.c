int cmp(const void*a,const void*b){
    int *aa = *(int**)a;
    int *bb = *(int**)b;
    if(aa[0]==bb[0]) return aa[1]-bb[1];
    return aa[0]-bb[0];
}
bool checkValidCuts(int n, int** rectangles, int rectanglesSize, int* rectanglesColSize) {
    int **tablex = malloc(rectanglesSize*sizeof(int*));
    int **tabley = malloc(rectanglesSize*sizeof(int*));
    for(int i=0;i<rectanglesSize;i++){
        tablex[i] = malloc(sizeof(int)*2);
        tabley[i] = malloc(sizeof(int)*2); 
    }
    for(int i=0;i<rectanglesSize;i++){
        int x_start = rectangles[i][0];
        int x_end   = rectangles[i][2];
        int y_start = rectangles[i][1];
        int y_end   = rectangles[i][3];
        tablex[i][0] = x_start;
        tablex[i][1] = x_end;
        tabley[i][0] = y_start;
        tabley[i][1] = y_end;
    }
    // do x-axis
    qsort(tablex,rectanglesSize,sizeof(int*),cmp);
    bool flag = false;
    int cut = 0;
    for(int i=1,prev_end = tablex[0][1];i<rectanglesSize;i++){
        int curr_start = tablex[i][0];
        int curr_end   = tablex[i][1];
        if(curr_start>=prev_end) cut++;
        prev_end = fmax(prev_end,curr_end);
    }
    if(cut>=2){
        flag = true;
        goto done;
    }
    // do y-axis
    cut = 0;
    qsort(tabley,rectanglesSize,sizeof(int*),cmp);
    for(int i=1,prev_end = tabley[0][1];i<rectanglesSize;i++){
        int curr_start = tabley[i][0];
        int curr_end   = tabley[i][1];
        if(curr_start>=prev_end) cut++;
        prev_end = fmax(prev_end,curr_end);
    }
    if(cut>=2){
        flag = true;
        goto done;
    }
    done:
        for(int i=0;i<rectanglesSize;i++){
            free(tablex[i]);
            free(tabley[i]); 
        }
        free(tablex);
        free(tabley);
    return flag;
}