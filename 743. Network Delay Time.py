    def networkDelayTime(self, times, n: int, k: int) -> int:
        # {x : [(y, z), ], }
        maxint = 999999
        graph = [[maxint for i in range(n+1)] for i in range(n+1)]
        for pair in times:
            graph[pair[0]][pair[1]] = pair[2]

        S = {k:0}
        U = {}
        # initiate U set
        for i in range(1, n+1):
            if i != k:
                U[i] = graph[k][i]
        for i in range(len(U)):
            sub_s = -1
            dist = maxint
            for u in U.keys():
                for s in S.keys():
                    d = graph[s][u] + S[s]
                    if d < dist:
                        dist = d
                        sub_s = u
            if sub_s != -1:
                S[sub_s] = dist
                U.pop(sub_s)
        if len(U) != 0:
            return -1
        return max(S.values())
