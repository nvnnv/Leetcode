    
    def __init__(self):
        self.ans = []
    def dfs(self, s, path):
        if len(s) == 0:
            self.ans.append(path)
        for i in range(1, len(s)+1):
            if s[:i] == s[:i][::-1]:
                self.dfs(s[i:], path +[s[:i]])
        
            
    def partition(self, s: str) -> List[List[str]]:
        self.ans = []
        self.dfs(s, [])
        return self.ans
