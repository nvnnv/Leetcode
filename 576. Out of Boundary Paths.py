  # backward dp  
  def findPaths(self, m: int, n: int, N: int, i: int, j: int) -> int:
        inf = 1e9 + 7
        dp = [[[0 for i in range(n)] for j in range(m)] for k in range(N)]
        offset = [(1,0),(-1,0),(0,-1),(0,1)]
        for k in range(N):
            for x in range(m):
                for y in range(n):
                    for a, b in offset:
                        newX = x + a
                        newY = y + b
                        if newX < 0 or newX >= m or newY < 0 or newY >= n:
                            if k == 0:
                                dp[k][x][y] += 1
                        else:
                            if k > 0:
                                dp[k][x][y] = (dp[k][x][y] + dp[k-1][newX][newY]) % inf
        count = 0
        for s in range(N):
            count = (dp[s][i][j] + count) % inf
        return count
      
 # forward dp
 too complex
