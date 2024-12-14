from collections import deque

class Solution:
    def continuousSubarrays(self, nums):
        n = len(nums)
        left = 0
        count = 0

        # Deques for tracking the max and min values in the current window
        max_deque = deque()  # Stores indices in decreasing order of value
        min_deque = deque()  # Stores indices in increasing order of value

        for right in range(n):
            # Update the max deque
            while max_deque and nums[max_deque[-1]] <= nums[right]:
                max_deque.pop()
            max_deque.append(right)

            # Update the min deque
            while min_deque and nums[min_deque[-1]] >= nums[right]:
                min_deque.pop()
            min_deque.append(right)

            # Shrink the window from the left to maintain the continuity condition
            while nums[max_deque[0]] - nums[min_deque[0]] > 2:
                left += 1
                # Remove indices that are no longer in the current window
                if max_deque[0] < left:
                    max_deque.popleft()
                if min_deque[0] < left:
                    min_deque.popleft()

            # Count subarrays ending at index `right`
            count += right - left + 1

        return count

