int findTargetSumWays(int* nums, int numsSize, int target) {
  int total = 0;
  for (int i = 0; i < numsSize; ++i) total += nums[i];
  if (total < abs(target)) return 0;
  int size = (total + 1) * 2, OFFSET = total, dp[size];
  for (int *dp_pos = dp + size - 1; dp_pos >= dp; --dp_pos) *dp_pos = 0;
  dp[total + OFFSET] = 1;  
  int min = total, max = total;
  for (int i = 0; i < numsSize; ++i) {
    for (int j = min; j <= max; ++j) {
      int matches = dp[j + OFFSET];
      if (matches) {
        int new_sum = j - nums[i] * 2;
        dp[new_sum + OFFSET] += matches;
        if (new_sum < min) min = new_sum;
        if (new_sum > max) max = new_sum;
      }
    }
  }
  return dp[target + OFFSET];
}