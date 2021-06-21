class Solution:
    def minKnightMoves(self, x: int, y: int) -> int:
        offsets = [[-2,1],[-1,2],[1,2],[2,1],[2,-1],[1,-2],[-1,-2], [-2, -1]]
        q = []
        q.append([0,0, 0])
        vis = {(0,0):1}
        while len(q) != 0:
            cur = q.pop(0)
            if cur[0]==x and cur[1]==y:
                return cur[2]
            for i, j in offsets:
                x1 = cur[0]-i
                y1 = cur[1]-j
                if x1<-(abs(x)+3) or y1<-(abs(y)+3) or x1>(abs(x)+3) or y1 >(abs(y)+3):
                    continue
                if vis.get((x1, y1)) is None:
                    vis[(x1,y1)]=1
                    q.append([x1,y1, cur[2]+1])
        return -1
        
        
        
        
        
class Solution:
    def minKnightMoves(self, x: int, y: int) -> int:
        offsets = [[-2,1],[-1,2],[1,2],[2,1],[2,-1],[1,-2],[-1,-2], [-2, -1]]
        q = []
        q.append([0,0, 0])
        vis = {(0,0):0}
        q1 = []
        q1.append([x,y, 0])
        vis1 = {(x,y):0}
        while True:
            cur = q.pop(0)
            if vis1.get((cur[0], cur[1])) is not None:
                return cur[2]+vis1[(cur[0],cur[1])]
            cur1 = q1.pop(0)
            if vis.get((cur1[0], cur1[1])) is not None:
                return cur1[2]+vis[(cur1[0], cur1[1])]
            for i, j in offsets:
                x1 = cur[0]+i
                y1 = cur[1]+j
                if vis.get((x1,y1)) is None:
                    vis[(x1,y1)] = cur[2]+1
                    q.append([x1,y1,cur[2]+1])
                x2 = cur1[0]+i
                y2 = cur1[1]+j
                if vis1.get((x2,y2)) is None:
                    vis1[(x2,y2)] = cur1[2]+1
                    q1.append([x2,y2,cur1[2]+1])
