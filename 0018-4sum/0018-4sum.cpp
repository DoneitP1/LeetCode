class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> resultVector;
        int n = nums.size();
        if (n < 4) return resultVector;

        sort(nums.begin(), nums.end());

        int left = 0;

        while (left < n - 3) {
            int right = n - 1;

            while (right > left + 2) {
                long long currentSum = nums[left] + nums[right];
                long long wanted = (long long)target - currentSum;

                int internalLeft = left + 1;
                int internalRight = right - 1;

                while (internalLeft < internalRight) {
                    long long internalSum =
                        nums[internalLeft] + nums[internalRight];

                    if (internalSum == wanted) {
                        resultVector.push_back({
                            nums[left],
                            nums[internalLeft],
                            nums[internalRight],
                            nums[right]
                        });

                        // skip duplicates
                        while (internalLeft < internalRight &&
                               nums[internalLeft] == nums[internalLeft + 1])
                            internalLeft++;

                        while (internalLeft < internalRight &&
                               nums[internalRight] == nums[internalRight - 1])
                            internalRight--;

                        internalLeft++;
                        internalRight--;
                    }
                    else if (internalSum < wanted) {
                        internalLeft++;
                    }
                    else {
                        internalRight--;
                    }
                }

                // skip duplicate right
                while (right > left + 2 && nums[right] == nums[right - 1])
                    right--;

                right--;
            }

            // skip duplicate left
            while (left < n - 3 && nums[left] == nums[left + 1])
                left++;

            left++;
        }

        return resultVector;
    }
};