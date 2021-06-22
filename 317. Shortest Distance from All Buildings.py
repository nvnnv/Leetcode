class Solution:
    def shortestDistance(self, grid: List[List[int]]) -> int:
        off = [[0,1],[1,0],[-1,0],[0,-1]]
        if len(grid) < 1:
            return -1
        size = [len(grid), len(grid[0])]
        start = []
        for i in range(size[0]):
            for j in range(size[1]):
                if grid[i][j] == 1:
                    start.append([i,j])
        g = [[[0 for i in range(len(start))] for i in range(size[1])] for i in range(size[0])]
        for i in range(len(start)):
            x,y = start[i]
            q = [(x, y, 0)]
            v  = {(x,y):0}
            
            while len(q) != 0:
                cur = q.pop(0)
                
                for j,k in off:
                    _x = cur[0]+j
                    _y = cur[1]+k
                    if _x < 0 or _y<0 or _x>=size[0] or _y>= size[1]:
                        continue
                    if grid[_x][_y] == 2 or v.get((_x,_y)) is not None or grid[_x][_y]==1:
                        continue
                    q.append([_x,_y, cur[2]+1])
                    v[(_x, _y)] = 1
                    g[_x][_y][i] = cur[2]+1
        #print(g)
        m = 9999999
        for i in g:
            for j in i:
                if 0 in j:
                    continue
                m = min (m, sum(j))
        if m == 9999999:
            return -1
        return m
                
