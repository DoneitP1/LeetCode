class Solution {
public:
    int titleToNumber(string columnTitle) {
        int sum=0;
        int j=0;
        map<char,int>cnt;
        int k=1;
        for(char ch='A';ch<='Z';ch++){
            cnt[ch]=k;
            k++;
        }
        for(int i=columnTitle.size()-1;i>=0;i--){
            sum+=(cnt[columnTitle[i]])*pow(26,j);
            j++;
        }
        return sum;
    }
};