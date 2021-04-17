import heapq as pq
class Solution:
    def shortestDistance(self, maze: List[List[int]], start: List[int], destination: List[int]) -> int:
        q = []
        offsets = [[-1,0],[1,0],[0,1],[0,-1]]

        # bfs pq
        pq.heappush(q, (0, (start[0],start[1])))
        v = {}
        while len(q) != 0:
            d, (x, y) = pq.heappop(q)
            if (x,y) == (destination[0], destination[1]):
                return d
            v[(x,y)] = 1
            for i, j in offsets:
                a, b = x, y
                step = 0
                while a >= 0 and b >= 0 and a < len(maze) and b < len(maze[0]) and maze[a][b] != 1:
                    a += i
                    b += j
                    step += 1
                a -= i
                b -= j
                step -= 1
                if v.get((a,b)) is None:
                    pq.heappush(q, (d+step, (a,b)))
                 
        return -1
                
        
                    
                    
