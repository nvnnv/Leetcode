class Solution:
    def getFood(self, grid: List[List[str]]) -> int:
        q = []
        offsets = [[0,1],[0,-1],[-1,0],[1,0]]
        size = [len(grid), len(grid[0])]
        v = {}
        for i in range(size[0]):
            for j in range(size[1]):
                if grid[i][j] == '*':
                    q.append((i,j, 0))
                    v[(i,j)] = 1
                    break
            if len(q) > 0:
                break
        
        ans = -1
        while len(q) > 0:
            x,y, s = q.pop(0)
            for i, j in offsets:
                xx = x+i
                yy = y+j
                if xx < 0 or yy < 0 or xx >= size[0] or yy >= size[1]:
                    continue
                if v.get((xx,yy)) is not None:
                    continue
                if grid[xx][yy] == 'X':
                    continue
                if grid[xx][yy] == '#':
                    ans = s+1
                q.append((xx,yy, s+1))
                v[(xx,yy)] = 1
            if ans != -1:
                break
        return ans
                
