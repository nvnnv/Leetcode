class Solution:
    def minimumSemesters(self, n: int, relations: List[List[int]]) -> int:
        graph = {i: [] for i in range(1, n+1)}
        indegree = [0 for i in range(0, n+1)]
        for i, j in relations:
            graph[i].append(j)
            indegree[j] += 1
        
        q = []
        hierarchy = [[]]
        for i in range(1, n+1):
            if indegree[i] == 0:
                q.append((i, 0))
                hierarchy[0].append(i)
        
        while len(q) != 0:
            head = q.pop(0)
            level = head[1]
            if level == len(hierarchy)-1:
                hierarchy.append([])
            for j in graph[head[0]]:
                indegree[j] -= 1
                if indegree[j] == 0:
                    q.append((j, level+1))
                    hierarchy[level+1].append(j)
                
        l = sum([len(i) for i in hierarchy])
        if l != n:
            return -1
        return len(hierarchy)-1
