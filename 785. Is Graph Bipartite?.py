    def isBipartite(self, graph) -> bool:
        B = {} #1
        W = {} #0
        V = {}
        # B can't to B, W can't to W
        f = [0]
        def dfs(cur, cur_color):
            for i in graph[cur]:
                if cur_color == 1:
                    if W.get(i) is None:
                        W[i] = 1
                    if B.get(i) is not None:
                        f[0] = 1
                        return
                else:
                    if B.get(i) is None:
                        B[i] = 1
                    if W.get(i) is not None:
                        f[0] = 1
                        return
            for i in graph[cur]:
                if V.get(i) is not None:
                    continue
                V[i] = 1
                if W.get(i) is not None:
                    a = 0
                else:
                    a = 1
                dfs(i, a)
                if f[0] == 1:
                    return
        for i in range(len(graph)):
            if V.get(i) is None:
                V[i] = 1
                if W.get(i) is not None:
                    a = 0
                    W[i] = 0
                else:
                    a = 1
                    B[i] = 1
                dfs(i, a)
        return not f[0]
