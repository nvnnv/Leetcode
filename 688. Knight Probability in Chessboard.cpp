   
# extremely classic 3-D dp

 def knightProbability(self, N: int, K: int, r: int, c: int) -> float:
        if K == 0:
            return 1.0
        dp = [[[0 for i in range(N)] for j in range(N)] for k in range(K+1)]
        dp[0][r][c] = 1
        offset = [(-1, -2),(1, -2),(2, -1),(2, 1),(1, 2),(-1, 2),(-2, 1),(-2, -1)]
        for steps in range(1, K+1):
            for i in range(N):
                for j in range(N):
                    for a, b in offset:
                        x = i + a
                        y = j + b
                        if x < 0 or y < 0 or x >= N or y >= N:
                            continue
                        dp[steps][i][j] += dp[steps-1][x][y]
        count = 0
        for i in range(N):
            for j in range(N):
                count += dp[steps][i][j]
        
        return count / 8**K
