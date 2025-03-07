class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        unordered_map<int, int>ump;
        for(int &i:deck) ump[i]++;
        int gcd_val = ump.begin()->second;
        for(auto it=ump.begin(); it!=ump.end(); it++) gcd_val = __gcd(gcd_val, it->second);
        return gcd_val != 1;
    }
};