class Solution {
public:
    int maxScore(string s) {
        // Count total number of 1's in the string
        int totalOnes = 0;
        for (char c : s) {
            if (c == '1') totalOnes++;
        }

        int leftZeroes = 0;  // Number of zeroes in the left part
        int rightOnes = totalOnes;  // Number of ones in the right part (initially all the ones)
        int maxScore = 0;  // To store the maximum score

        // Iterate through the string and check score at each position
        for (int i = 0; i < s.length() - 1; i++) {  // We don't consider the last split as it leaves the right part empty
            if (s[i] == '0') {
                leftZeroes++;  // Increment leftZeroes if it's a 0
            } else {
                rightOnes--;  // Decrement rightOnes if it's a 1
            }

            // Update the maximum score
            maxScore = max(maxScore, leftZeroes + rightOnes);
        }

        return maxScore;
    }
};