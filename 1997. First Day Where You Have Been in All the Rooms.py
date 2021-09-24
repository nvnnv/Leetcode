class Solution:
    def firstDayBeenInAllRooms(self, nextVisit: List[int]) -> int:
        mod = 1e9 + 7
        dp = [0 for i in nextVisit]
        
        p = nextVisit
        for i in range(1, len(p)):
            dp[i] = (dp[i-1] + (dp[i-1] - dp[p[i-1]])+2) % mod
        #print(dp)
        return int(dp[-1])
