class Solution:
    
    def __init__(self):
        self.visited = []
        self.ans = []
        
    def dfs(self,b, i, n, k, cur_a):
        if b == k:
            self.ans.append(cur_a.copy())
            return
        
        for j in range(i, n+1):
            if self.visited[j] == 0:
                self.visited[j] = 1
                cur_a.append(j)
                self.dfs(b+1, j+1, n, k, cur_a)
                cur_a.pop(-1)
                self.visited[j] = 0
                
    def combine(self, n: int, k: int) -> List[List[int]]:
        self.ans = []
        self.visited = [0 for i in range(n+1)]
        self.dfs(0, 1, n, k, [])
        return self.ans
