class Solution {
public:
    int maxScore(string s) {
        int totalOnes = 0;
        for (char c : s) {
            if (c == '1') totalOnes++;
        }

        int leftZeroes = 0;  
        int rightOnes = totalOnes;  
        int maxScore = 0;  
        for (int i = 0; i < s.length() - 1; i++) {  
            if (s[i] == '0') {
                leftZeroes++;  
            } else {
                rightOnes--;  
            }

            
            maxScore = max(maxScore, leftZeroes + rightOnes);
        }

        return maxScore;
    }
};