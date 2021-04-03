class Solution:

    def constructDistancedSequence(self, n: int) -> List[int]:
        ans = [0 for i in range(1+(n-1)*2)]
        v = [0 for i in range(0, n+1)]
        
        def dfs(i, m, n):
            if i == m:
                return True
            if ans[i] != 0:
                return dfs(i+1, m, n)
            
            for j in range(n, 0, -1):
                if v[j] == 0 and j == 1:
                    v[j] = 1
                    ans[i] = 1
                    if dfs(i+1, m,n):
                        return True
                    ans[i] = 0
                    v[j] = 0
                else:
                    if v[j] == 0 and j+i < m and ans[j+i] == 0:
                        v[j] = 1
                        ans[i] = j
                        ans[j+i] = j
                        if dfs(i+1, m, n):
                            return True
                        ans[j+i] = 0
                        ans[i] = 0
                        v[j] = 0
            return False
        dfs(0, 1+(n-1)*2, n)   
        return ans
                            
