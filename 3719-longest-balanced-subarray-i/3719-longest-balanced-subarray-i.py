class Solution:
    def longestBalanced(self, nums):
        n = len(nums)
        max_len = 0
        
        # Iterate over every starting point of the subarray
        for i in range(n):
            distinct_evens = set()
            distinct_odds = set()
            
            # Expand the subarray from i to the end of the list
            for j in range(i, n):
                # Check if the current number is even or odd
                # and add to the respective set to track uniqueness
                if nums[j] % 2 == 0:
                    distinct_evens.add(nums[j])
                else:
                    distinct_odds.add(nums[j])
                
                # If the count of distinct evens equals distinct odds, update max_len
                if len(distinct_evens) == len(distinct_odds):
                    max_len = max(max_len, j - i + 1)
                    
        return max_len
        