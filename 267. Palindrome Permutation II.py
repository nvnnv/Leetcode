class Solution:
    def generatePalindromes(self, s: str) -> List[str]:
        if s is None or len(s) == 0:
            return []
        
        ans = []
        v = {}
        for c in s:
            if v.get(c) is None:
                v[c] = 0
            v[c] += 1
        
        def dfs(i, permutation):
            l = len(s)
            prev = permutation
            lp = len(permutation)
            if i == l:
                ans.append(permutation)
                return
            if i == l-1:
                for pairs in v.items():
                    if pairs[1] == 1:
                        ans.append(permutation[:lp//2] + pairs[0] + permutation[lp//2:])
                        return
            
            for c in v.keys():
                if v[c] >= 2:
                    v[c] -= 2
                    permutation = permutation[:lp//2] + c+c + permutation[lp//2:] 
                    dfs(i+2, permutation)
                    permutation = prev
                    v[c] += 2
                    
        dfs(0, '')
        return ans
        
