class Solution:
    def wallsAndGates(self, rooms: List[List[int]]) -> None:
        """
        Do not return anything, modify rooms in-place instead.
        """
        offsets = [[0,1],[1,0],[0,-1],[-1,0]]
        size = [len(rooms), len(rooms[0])]
        q = []
        for i in range(len(rooms)):
            for j in range(len(rooms[i])):
                if rooms[i][j] == 0:
                    q.append([i,j])
        while len(q) != 0:
            cur = q.pop(0)
            for i in offsets:
                x = cur[0]+i[0]
                y = cur[1]+i[1]
                if x >= size[0] or x<0 or y>=size[1] or y<0 or rooms[x][y] != 2147483647:
                    continue
                rooms[x][y] = rooms[cur[0]][cur[1]]+1
                q.append([x,y])
