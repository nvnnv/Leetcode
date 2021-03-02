    def pacificAtlantic(self, matrix):
        if len(matrix) == 0:
            return []
        size = [len(matrix), len(matrix[0])]

        offset = [(0,1),(0,-1),(1,0),(-1,0)]
        pacific = [[0 for i in range(size[1])] for j in range(size[0])]
        atlantic = [[0 for i in range(size[1])] for j in range(size[0])]

        def dfs(x, y, preVal, graph):
            # necessary condition judgement
            if x < 0 or y < 0 or x >= size[0] or y >= size[1]:
                return
            if matrix[x][y] < preVal:
                return
            if graph[x][y] == 1:
                return
            # process the cell
            graph[x][y] = 1
            # real dfs
            for i, j in offset:
                newX = x + i
                newY = y + j
                dfs(newX, newY, matrix[x][y], graph)
        # traverse top and bottom
        for i in range(size[1]):
            dfs(0, i, 0, pacific)
            dfs(size[0]-1, i, 0, atlantic)
        for i in range(size[0]):
            dfs(i, 0, 0, pacific)
            dfs(i, size[1]-1, 0, atlantic)
        # comparsion pacific and atlantic
        res = []
        for i in range(size[0]):
            for j in range(size[1]):
                if pacific[i][j] == 1 and 1 == atlantic[i][j]:
                    res.append([i, j])
        return res
