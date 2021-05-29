    def minSideJumps(self, obstacles: List[int]) -> int:
        dp = [1,0,1]
        for i in range(1, len(obstacles)):
            if obstacles[i] == 0:
                dp[0] = min(dp[1]+1, dp[2]+1, dp[0])
                dp[1] = min(dp[1], dp[2]+1, dp[0]+1)
                dp[2] = min(dp[1]+1, dp[2], dp[0]+1)
            if obstacles[i] == 1:
                dp[0] = 1e9
                dp[1] = min(dp[1], dp[2]+1, dp[0]+1)
                dp[2] = min(dp[1]+1, dp[2], dp[0]+1)
            if obstacles[i] == 2:
                dp[1] = 1e9
                dp[0] = min(dp[1]+1, dp[2]+1, dp[0])
                dp[2] = min(dp[1]+1, dp[2], dp[0]+1)
            if obstacles[i] == 3:
                dp[2] = 1e9
                dp[0] = min(dp[1]+1, dp[2]+1, dp[0])
                dp[1] = min(dp[1], dp[2]+1, dp[0]+1)
                    
        return min(dp)
