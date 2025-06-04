int firstBadVersion(int n) {
   long int f=1,mid;
    while(f<n) {
        mid = (f+n) / 2;
        if(isBadVersion(mid) == true) {
            n=mid;
        }
        else {
            f=mid+1;
        }
    }
    return f;
}
