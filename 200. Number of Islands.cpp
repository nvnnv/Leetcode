    def numIslands(self, grid) -> int:
        offset = [[1,0],[-1,0],[0,1],[0,-1]]
        size = [len(grid), len(grid[0])]
        def reflag(cur, f, ref):
            if grid[cur[0]][cur[1]] != f:
                return
            grid[cur[0]][cur[1]] = ref
            for i in offset:
                x = cur[0] + i[0]
                y = cur[1] + i[1]
                if x >=0 and x<size[0] and y>=0 and y<size[1]:
                    reflag([x, y], f, ref)
        num = 0
        for i in range(size[0]):
            for j in range(size[1]):
                if grid[i][j] == '1':
                    reflag([i,j], '1', '#')
                    num += 1
        return num
