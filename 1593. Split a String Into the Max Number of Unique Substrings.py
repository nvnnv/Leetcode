    
    def maxUniqueSplit(self, s: str) -> int:
        ans = []
        l = [0]
        
        def dfs(ss):
            l[0] = max(len(ans), l[0])
            if len(ss) == 0:
                return
            
            for j in range(1, len(ss) + 1):
                sub = ss[:j]
                if sub not in ans:
                    ans.append(sub)
                    dfs(ss[j:])
                    ans.pop(-1)
            
        dfs(s)
        return l[0]
