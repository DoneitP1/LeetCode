int mirrorReflection(int p, int q){
    if (p == q) return 1;
    int height = q, right = 0, up = 1;
    
    while (1){
        if (height + q == p){
            if (right && up) return 1;
            else if (!right && up) return 2;
            else return 0;
        }else if (height + q < p){
            height += q;
            right = !right;
        }else{          
            height += q - p;
            right = !right;
            up = !up;
        }
    }
}