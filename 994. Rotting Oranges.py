class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        offset = [[0,1],[0,-1], [1,0],[-1,0]]
        size = [len(grid), len(grid[0])]
        vis = [[0 for i in range(size[1])] for j in range(size[0])]
        q = []
        count = 0
        for i in range(size[0]):
            for j in range(size[1]):
                if grid[i][j] == 2:
                    q.append([i,j, 0])
                    count += 1
                if grid[i][j] == 1:
                    count += 1
        ans = 0
        c = 0
        while len(q) != 0:
            cur = q.pop(0)
            c += 1

            ans = max(cur[2], ans)
            for i in offset:
                x = cur[0]+i[0]
                y = cur[1]+i[1]
                if x>=size[0] or x<0 or y>=size[1] or y<0:
                    continue
                if grid[x][y] == 1 and vis[x][y]==0:
                    vis[x][y] = 1
                    q.append([x,y,cur[2]+1])
        if c != count:
            return -1
        return ans
