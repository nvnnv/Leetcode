class Solution:
    def splitIntoFibonacci(self, S: str) -> List[int]:
        if S is None or len(S) == 0:
            return []
        
        ans = []
        def dfs(s, arr):
            if len(arr) > 2:
                if arr[-1] != (arr[-2] + arr[-3]):
                    return
                if s == '':
                    ans.append(arr)
                    return
            
            for i in range(1, len(s)+1):
                sub = s[:i]
                if len(sub) > 1 and sub[0] == '0':
                    return
                j = int(sub)
                if j > 2147483647:
                    return
                arr.append(j)
                dfs(s[i:], arr)
                if len(ans) > 0:
                    return
                arr.pop(-1)
                
        dfs(S, [])
        if len(ans) == 0:
            return []
        return ans[0]    
