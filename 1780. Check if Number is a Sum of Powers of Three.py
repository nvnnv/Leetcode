class Solution:
    def __init__(self):
        self.f = False
        
    def dfs(self, x, s, n):
        if s == n:
            self.f = True
            return
        if s > n or (3**x) > n:
            return


        self.dfs(x+1, s + 3**x, n)
        self.dfs(x+1, s, n)
        
    def checkPowersOfThree(self, n: int) -> bool:
        self.f = False
        self.dfs(0, 0, n)
        return self.f
