class Solution:
    def hasPath(self, maze: List[List[int]], start: List[int], destination: List[int]) -> bool:
        v = {}
        offsets = [[1,0],[-1,0],[0,1],[0,-1]]
        v = {}
        def dfs(x, y, d):
            if v.get((x,y)) is not None:
                return -1
            if x <0 or y<0 or x>= len(maze) or y>=len(maze[0]):
                return -1
            if maze[x][y] == 1:
                return -1
            
            c = 0 if d == 1 else 1 if d == 0 else 2 if d==3 else 3 if d == 2 else -1
            if d != -1:
                direct = offsets[d]
                a, b = x, y
                while a >= 0 and b>=0 and a< len(maze) and b<len(maze[0]) and maze[a][b] != 1:
                    a = a + direct[0]
                    b = b + direct[1]
                x = a - direct[0]
                y = b - direct[1]
                if v.get((x,y)) is not None:
                    return -1
                d = -1
            if d == -1:
                if x == destination[0] and y == destination[1]:
                    return 100
                v[(x,y)] = 1
                for i, coor in enumerate(offsets):
                    if i == c:
                        continue
                    d = dfs(x+coor[0], y+coor[1], i)
                    if d == 100:
                        return d
            
            return -1
        if dfs(start[0], start[1], -1) == 100:
            return True
        else:
            return False
