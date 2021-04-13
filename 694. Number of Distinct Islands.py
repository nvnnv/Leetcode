class Solution:
    def numDistinctIslands(self, grid: List[List[int]]) -> int:
        ans = []
        size = [len(grid), len(grid[0])]
        s = ['']
        
        def dfs(x, y):
            if x < 0 or y < 0 or x >= size[0] or y >= size[1]:
                return
            if grid[x][y] != 1:
                return

            grid[x][y] = 2
            s[0] += '1'
            dfs(x+1, y)
            s[0] += '2'
            dfs(x-1, y)
            s[0] += '3'
            dfs(x, y+1)
            s[0] += '4'
            dfs(x, y-1)

        for i in range(size[0]):
            for j in range(size[1]):
                if grid[i][j] == 1:
                    dfs(i, j)
                    if s[0] not in ans:
                        ans.append(s[0])
                    s[0] = ''

        return len(ans)
class Solution:
    def numDistinctIslands(self, grid: List[List[int]]) -> int:
        ans = []
        size = [len(grid), len(grid[0])]
        p = [()]
        def dfs(x, y, i, j):
            if x < 0 or y < 0 or x >= size[0] or y >= size[1]:
                return
            if grid[x][y] != 1:
                return

            grid[x][y] = 0
            p[0] += (x-i, y-j)
            dfs(x+1, y,i,j)
            dfs(x-1, y,i,j)
            dfs(x, y+1,i,j)
            dfs(x, y-1,i,j)

        mapping = {}
        for i in range(size[0]):
            for j in range(size[1]):
                if grid[i][j] == 1:
                    dfs(i, j, i, j)
                    if mapping.get(p[0]) is None:
                        mapping[p[0]] = 1
                    p[0] = ()

        return len(mapping)
