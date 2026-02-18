class Solution(object):
    def uniquePaths(self, m, n):
        # Check if either dimension is zero, return 0 paths
        if n == 0 or m == 0 :
            return 0

        # Initialize a 2D array to store the number of unique paths for each cell
        ans = [[0] * n for _ in range(m)]

        # Set the number of paths for the first row to 1
        for i in range(n):
            ans[0][i] = 1
        # Set the number of paths for the first column to 1
        for i in range(m):
            ans[i][0] = 1

        # Calculate the number of paths for each cell in the grid
        for i in range(1,m):
            for j in range(1,n):
                # The number of paths to reach cell (i, j) is the sum of paths
                # from the cell above (i-1, j) and the cell to the left (i, j-1)
                ans[i][j] = ans[i-1][j] + ans[i][j-1]

        # The result is stored in the bottom-right cell of the grid   
        return ans[m-1][n-1]