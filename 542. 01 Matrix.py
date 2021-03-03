    def updateMatrix(self, matrix):
        if len(matrix) == 0:
            return []
        size = (len(matrix), len(matrix[0]))
        """
        # BFS
        offset = [(0, 1), (0, -1), (1, 0), (-1, 0)]
        distance = [[0 for i in range(size[1])] for j in range(size[0])]
        def bfs(x, y):
            visited = {}
            q = queue.Queue()
            q.put((x, y, 0))
            while not q.empty():
                i, j, d = q.get()
                visited[(i, j)] = 1
                for a, b in offset:
                    newX = i + a
                    newY = j + b
                    if newX < 0 or newX >= size[0] or newY < 0 or newY >= size[1] or visited.get((newX, newY)) is not None:
                        continue
                    if matrix[newX][newY] == 0:
                        return d + 1
                    q.put((newX, newY, d+1))
            return dist

        for i in range(size[0]):
            for j in range(size[1]):
                if matrix[i][j] == 1:
                    distance[i][j] = bfs(i, j)
        return distance
        """
        # DP
        dp = [[0 if matrix[i][j] == 0 else 99999 for j in range(size[1])] for i in range(size[0])]

        for i in range(size[0]):
            for j in range(size[1]):
                if matrix[i][j] == 1:
                    if i - 1 >= 0:
                        if matrix[i-1][j] == 0:
                            dp[i][j] = 1
                        else:
                            dp[i][j] = min(dp[i][j], dp[i-1][j]+1)
                    if j - 1 >= 0:
                        if matrix[i][j-1] == 0:
                            dp[i][j] = 1
                        else:
                            dp[i][j] = min(dp[i][j], dp[i][j-1]+1)
        for i in range(size[0]-1, -1, -1):
            for j in range(size[1]-1, -1, -1):
                if matrix[i][j] == 1:
                    if i + 1 < size[0]:
                        if matrix[i+1][j] == 0:
                            dp[i][j] = 1
                        else:
                            dp[i][j] = min(dp[i][j], dp[i+1][j]+1)
                    if j + 1 < size[1]:
                        if matrix[i][j+1] == 0:
                            dp[i][j] = 1
                        else:
                            dp[i][j] = min(dp[i][j], dp[i][j+1]+1)
        return dp
