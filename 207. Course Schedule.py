    def canFinish(self, numCourses: int, prerequisites) -> bool:
        graph = {i:[] for i in range(numCourses)}
        visited = [0 for i in range(numCourses)]
        f = [True]
        for i, j in prerequisites:
            graph[i].append(j)
        def dfs(cur):
            visited[cur] = 1
            for i in graph[cur]:
                if visited[i] == 0:
                    dfs(i)
                elif visited[i] == 1:
                    f[0] = False
            visited[cur] = 2

        for i in range(numCourses):
            if len(graph[i]) != 0 and visited[i] == 0:
                dfs(i)

        return f[0]
      
      
      
      
   def canFinish(self, numCourses: int, prerequisites) -> bool:
        graph = {i:[] for i in range(numCourses)}
        visited = [0 for i in range(numCourses)]
        f = [True]
        for i, j in prerequisites:
            graph[i].append(j)
        def dfs(cur, x):
            if visited[cur] == 1:
                f[0] = False
                return
            if visited[cur] == 2:
                return
            visited[cur] = x
            for i in graph[cur]:
                dfs(i, 2)
        for i in range(numCourses):
            if len(graph[i]) != 0:
                dfs(i, 1)
            visited = [0 for i in range(numCourses)]
        return f[0]
