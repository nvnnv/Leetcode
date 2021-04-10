class Solution:
    def findStrobogrammatic(self, n: int) -> List[str]:
        if n < 1:
            return []
        
        seq = ['0','1','6','8','9']
        
        ans = []
        def dfs(cur, i):
            if len(cur) > 1 and cur[0] == '0':
                return
            if i == n:
                ans.append(cur)
                return
            if i == (n-1):
                for c in ['0','1','8']:
                    s = cur[:len(cur)//2] + c + cur[len(cur)//2:]
                    ans.append(s)
                return
            
            for c in seq:
                if c == '6':
                    s = cur[:len(cur)//2] + c + '9' + cur[len(cur)//2:]
                    dfs(s, i+2)
                    continue
                if c == '9':
                    s = cur[:len(cur)//2] + c + '6' + cur[len(cur)//2:]
                    dfs(s, i+2)
                    continue
                s = cur[:len(cur)//2] + c + c + cur[len(cur)//2:]
                dfs(s, i+2)
                
        dfs('', 0)
        return ans
