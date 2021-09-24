class Solution:
    def maxProductPath(self, grid: List[List[int]]) -> int:
        def minmax(x, a, b):
            mi = 1e9
            ma = -1e9
            for i in a:
                c = i*x
                mi = min(c, mi)
                ma = max(c, ma)
            for j in b:
                c = x*j
                mi = min(c, mi)
                ma = max(c, ma)
            return mi, ma
        size = [len(grid), len(grid[0])]
        dp = [[[1, 1] for j in range(size[1])] for i in range(size[0])]
        dp[0][0] = [grid[0][0], grid[0][0]]
        for i in range(size[0]):
            for j in range(size[1]):
                if i == 0 and j != 0:
                    dp[0][j] = minmax(grid[0][j], dp[0][j-1], [])
                if i != 0 and j == 0:
                    dp[i][0] = minmax(grid[i][0], [], dp[i-1][0])
                if i!=0 and j !=0:
                    dp[i][j] = minmax(grid[i][j], dp[i][j-1], dp[i-1][j])
        #print(dp)
        return -1 if max(dp[-1][-1]) < 0 else int(max(dp[-1][-1])%(1e9+7))
