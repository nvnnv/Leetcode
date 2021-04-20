# """
# This is GridMaster's API interface.
# You should not implement it, or speculate about its implementation
# """
#class GridMaster(object):
#    def canMove(self, direction: str) -> bool:
#        
#
#    def move(self, direction: str) -> int:
#        
#
#    def isTarget(self) -> None:
#        
#
import heapq as pq
class Solution(object):
    def findShortestPath(self, master: 'GridMaster') -> int:
        # 
        line = []
        ds = ['U','D','L','R']
        offsets = [[-1,0],[1,0],[0,-1],[0,1]]
        v = {}
        start = [101,101]
        end = [[-1,-1]]
        def dfs(master, x, y, val):
            if v.get((x,y)) is not None:
                return
            if val < 0:
                end[0] = [x, y]
                val = -val
            line.append(((x,y), val))
            v[(x,y)] = 1
            for i in range(len(ds)):
                if master.canMove(ds[i]):
                    p=master.move(ds[i])
                    if master.isTarget():
                        p = -p
                    dfs(master,x+offsets[i][0], y+offsets[i][1], p)
                    if ds[i] == 'U':
                        master.move('D')
                    if ds[i] == 'D':
                        master.move('U')
                    if ds[i] == 'L':
                        master.move('R')
                    if ds[i] == 'R':
                        master.move('L')
        dfs(master, 101,101, 0)
        line = sorted(line, key=lambda x: (x[0][0],x[0][1]))
        graph = {}
        for i in range(len(line)):
            graph[line[i][0]] = line[i][1]
        q = []
        pq.heappush(q, (graph[(start[0],start[1])], (start[0],start[1])))
        v = {}
        while len(q) != 0:
            d, (x,y) = pq.heappop(q)
            if (x, y) == (end[0][0], end[0][1]):
                return d
            v[(x,y)] = 1
            for i, j in offsets:
                nx = x+i
                ny = y+j
                if graph.get((nx, ny)) is None:
                    continue
                if v.get((nx,ny)) is not None:
                    continue
                pq.heappush(q, (d+graph[(nx,ny)], (nx, ny)))
        return -1
