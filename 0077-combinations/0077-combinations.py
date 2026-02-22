from itertools import combinations

class Solution(object):
    def combine(self, n, k):
        """
        :type n: int
        :type k: int
        :rtype: List[List[int]]
        """
        arr = list(range(1, n + 1))
        out = []

        for c in combinations(arr, k):
            out.append(c)
        return(out)