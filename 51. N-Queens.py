class Solution:
    def solveNQueens(self, n: int) -> List[List[str]]:
        def muji(x,y):
            for i, j in q:
                if abs(i-x) == abs(j-y):
                    return False
            return True
        vis = [0 for i in range(n)]
        q = []
        ans = []
        def dfs(c):
            if c == n:
                t = []
                for i,j in q:
                    s = '.'*n
                    t.append(s[:j] + 'Q' + s[j+1:])
                ans.append(t)
                return

            for j in range(n):
                if vis[j] == 0 and muji(c,j) is True:
                    vis[j] = 1
                    q.append([c,j])
                    dfs(c+1)
                    q.pop(-1)
                    vis[j] = 0
        
        dfs(0)
        return ans
