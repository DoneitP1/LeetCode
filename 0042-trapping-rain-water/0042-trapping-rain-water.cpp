class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int> lmax;
        int max_right=-1;
        int max_left=-1;
        int blocks=0; /// your result
        for (int i=0;i<n;i++){
            lmax.push_back(max_left);
            max_left = max(max_left,height[i]);
        } // save value of left max value before the selected elemet 
        for (int i=n-1;i>=0;i--){
            lmax[i]=min(max_right,lmax[i]);
            max_right = max(max_right,height[i]);
        } /// see down
// findes the right most max value from tha and compare with left most max value and save the min of them
        for (int i=0;i<n;i++){
            if (lmax[i]==-1) continue;
            if ((lmax[i]-height[i])>=0) blocks+=lmax[i]-height[i];
        } // if height diff exist and is positive add the height difference
    return blocks;
    }
};