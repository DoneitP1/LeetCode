class Solution:
    def findScore(self, nums):
        # Create a list of tuples containing each element and its original index
        indexed_nums = [(num, i) for i, num in enumerate(nums)]
        # Sort based on the number value
        indexed_nums.sort()

        score = 0
        marked = [False] * len(nums)

        for num, idx in indexed_nums:
            if not marked[idx]:
                score += num
                # Mark the current index and its neighbors
                marked[idx] = True
                if idx > 0: marked[idx - 1] = True
                if idx < len(nums) - 1: marked[idx + 1] = True

        return score

def _driver():
    param_1 = [2, 1, 3, 4, 5, 2]  # Example input
    ret = Solution().findScore(param_1)
    print(ret)

if __name__ == "__main__":
    _driver()
