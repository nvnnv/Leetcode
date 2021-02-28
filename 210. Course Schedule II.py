    def findOrder(self, numCourses: int, prerequisites):
        graph = {i:[] for i in range(numCourses)}
        inDegree = [0 for i in range(numCourses)]
        for i, j in prerequisites:
            inDegree[j] += 1
            graph[i].append(j)
        topo = []
        q = queue.Queue()
        for i, j in enumerate(inDegree):
            if j == 0:
                q.put(i)
        while not q.empty():
            p = q.get()
            topo.append(p)
            for i in graph[p]:
                if inDegree[i] != 0:
                    inDegree[i] -= 1
                if inDegree[i] == 0:
                    q.put(i)
        if len(topo) < numCourses:
            return []
        topo.reverse()
        return topo
