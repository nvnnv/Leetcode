    def possibleBipartition(self, N: int, dislikes) -> bool:
        graph = {i: [] for i in range(N+1)}
        for i, j in dislikes:
            graph[i].append(j)
            graph[j].append(i)
        color = [0 for i in range(N+1)]
        def dfs(cur, col):
            color[cur] = col
            for i in graph[cur]:
                if color[i] == color[cur]:
                    F[0] = False
                if not color[i]:
                    dfs(i, 3-col)
        F = [True]
        for i in range(1, N+1):
            if not color[i]:
                dfs(i,1)
        return F[0]
