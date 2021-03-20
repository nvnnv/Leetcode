   # 28ms
   def countVowelStrings(self, n: int) -> int:
        
        dp = [[0, 0, 0, 0, 0] for i in range(n)]
        dp[0] = [1,1,1,1,1]
        for i in range(1, n):
            dp[i][4] = dp[i-1][4]
            dp[i][3] = sum(dp[i-1][3:])
            dp[i][2] = sum(dp[i-1][2:])
            dp[i][1] = sum(dp[i-1][1:])
            dp[i][0] = sum(dp[i-1])
        
        return sum(dp[n-1])
        
       # 1000ms 
   def countVowelStrings(self, n: int) -> int:
        
        c = [0]
        letter_sl = 5
        def dfs(i, cur_l):
            if cur_l == n or i == 4:
                c[0] += 1
                return 
            
            for j in range(i, letter_sl):
                dfs(j, cur_l+1)
            
        dfs(0, 0)
        return c[0]
    # 5000ms    
 def countVowelStrings(self, n: int) -> int:
        
        c = [0]
        letter_sl = 5
        def dfs(i, cur_l):
            if cur_l == n:
                c[0] += 1
                return 
            
            for j in range(i, letter_sl):
                dfs(j, cur_l+1)
            
        dfs(0, 0)
        return c[0]
