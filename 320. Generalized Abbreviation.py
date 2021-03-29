    def generateAbbreviations(self, word: str) -> List[str]:
        ans = []
        visited = {}
        def dfs(s, cur_s, f):
            if visited.get(cur_s) is not None:
                return
            if not s:
                visited[cur_s] = 1
                return
            
            for i in range(1, len(s)+1):
                sub = s[:i]
                if f == 2:
                    dfs(s[i:], cur_s+str(len(sub)), 1)
                    dfs(s[i:], cur_s + sub, 2)
                if f == 1:
                    dfs(s[i:], cur_s + sub, 2)
        
        dfs(word, "", 2)
        return visited.keys()
 
# 98%
    def generateAbbreviations(self, word: str) -> List[str]:
        ans = []
        visited = {}
        def dfs(i, s, f):
            if i == len(word):
                ans.append(s + (str(f) if f>0 else ""))
                return
            
            dfs(i+1, s, f+1)
            dfs(i+1, s + (str(f) if f > 0 else "") + word[i], 0)
        
        dfs(0, "", 0)
        return ans
