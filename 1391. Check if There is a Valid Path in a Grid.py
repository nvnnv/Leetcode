    def hasValidPath(self, grid) -> bool:
        offset = [(0,1),(0,-1),(1,0),(-1,0)]
        H = {(3,2):1, (4,2):1, (2,5):1, (2,6):1, (4,5):1, (3,6):1, (2,2):1, (3,5):1,(4,6):1}
        V = {(1,3):1,(1,5):1,(4,1):1,(6,1):1,(4,3):1,(6,5):1, (1,1):1}
        size = (len(grid), len(grid[0]))
        F = [False]
        visit = [[0 for i in range(size[1])] for j in range(size[0])]
        def dfs(x,y):
            if x == size[0]-1 and y == size[1]-1:
                F[0] = True
                return
            if visit[x][y] != 0:
                return
            visit[x][y]=1
            nx = x + offset[0][0]
            ny = y + offset[0][1]
            if nx >= 0 and nx < size[0] and ny >= 0 and ny < size[1]:
                if V.get((grid[x][y], grid[nx][ny])) is not None:
                    dfs(nx, ny)
            nx = x + offset[1][0]
            ny = y + offset[1][1]
            if nx >= 0 and nx < size[0] and ny >= 0 and ny < size[1]:
                if V.get((grid[nx][ny], grid[x][y])) is not None:
                    dfs(nx, ny)
            nx = x + offset[2][0]
            ny = y + offset[2][1]
            if nx >= 0 and nx < size[0] and ny >= 0 and ny < size[1]:
                if H.get((grid[x][y], grid[nx][ny])) is not None:
                    dfs(nx, ny)
            nx = x + offset[3][0]
            ny = y + offset[3][1]
            if nx >= 0 and nx < size[0] and ny >= 0 and ny < size[1]:
                if H.get((grid[nx][ny], grid[x][y])) is not None:
                    dfs(nx, ny)
        dfs(0,0)
        return F[0]
