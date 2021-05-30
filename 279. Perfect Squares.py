import math
# 194ms
class Solution:
    
    def numSquares(self, n: int) -> int:
        pp = []
        for i in range(1, n):
            if i*i<=n:
                pp.append(i*i)
            else:
                break
        
        dd = {}
        for i in pp:
            dd[i] = 1
        q = {n}
        ans = 0 
        while q:
            ans += 1
            nq = set()
            for i in q:
                for j in pp:
                    if i == j:
                        return ans
                    if j > i:
                        break
                    nq.add(i-j)
            q = nq
        return ans
        
        
import math
class Solution:
    
    def numSquares(self, n: int) -> int:
        dp = [1e9 for i in range(10000)]
        dp[1]=1
        dp[2]=2
        dp[3]=3
        def dfs(n):
            if dp[n] != 1e9:
                return dp[n]
            if n == 0:
                return 0
            i = 1
            while i*i <= n:
                f = dfs(n - i*i)+1
                i += 1
                dp[n] = min(dp[n], f)
            return dp[n]
        
        
        dfs(n)
        return dp[n]
