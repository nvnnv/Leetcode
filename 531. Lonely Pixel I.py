class Solution:
    def findLonelyPixel(self, picture: List[List[str]]) -> int:
        v = {}
        offsets = [[1,0],[-1,0],[0,1],[0,-1]]
        def dfs(x, y, d):
            if x < 0 or y < 0 or x >= len(picture) or y >= len(picture[0]):
                return 1
            if v.get((x,y)) is not None:
                return 0
            if picture[x][y] == 'B':
                v[(x,y)] = 1
            if d == -1:
                s = 0
                for k, p in enumerate(offsets):
                    i, j = p[0], p[1]
                    nx = x + i
                    ny = y + j
                    s += dfs(nx, ny, k)
                if s == 4:
                    return 1
                else:
                    return 0
            else:
                if picture[x][y] == 'B':
                    return 0
                return dfs(x+offsets[d][0], y+offsets[d][1], d)

        
        ans = 0
        for i in range(len(picture)):
            for j in range(len(picture[0])):
                if picture[i][j] == 'B' and v.get((i, j)) is None:
                    ans += dfs(i,j, -1) 
        return ans
