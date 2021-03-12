class Node:
    def __init__(self, num, sign):
        self.id = num
        self.sign = sign
        # self.par = None
        self.children = []
        
class Solution:
    def countSubTrees(self, n: int, edges: List[List[int]], labels: str) -> List[int]:
        # create adjacency list
        graph = {i: [] for i in range(n)}
        for i, j in edges:
            graph[i].append(j)
            graph[j].append(i)
        # create tree
        def tree(cur, par):
            if graph.get(cur) is None:
                return
            node = Node(cur, labels[cur])
            for i in graph[cur]:
                if i == par:
                    continue
                n1 = tree(i, cur)
                # n1.par = node
                node.children.append(n1)
            return node
        
        root = tree(0, -1)
        
        ans = [0 for i in range(n)]
        def dfs(cur):
            if cur is None:
                return None
            
            xo = {}
            for i in cur.children:
                l = dfs(i)
                if i is not None:
                    for key, val in l.items():
                        if xo.get(key) is None:
                            xo[key] = val
                        else:
                            xo[key] += val
            if xo.get(cur.sign) is None:
                xo[cur.sign] = 1
            else:
                xo[cur.sign] += 1
            
            ans[cur.id] = xo[cur.sign]
            return xo
        
        dfs(root)
        return ans
        
