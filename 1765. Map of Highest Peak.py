import heapq as pq
class Solution:
    def highestPeak(self, isWater: List[List[int]]) -> List[List[int]]:
        q = []
        size = [len(isWater), len(isWater[0])]
        for i in range(size[0]):
            for j in range(size[1]):
                if isWater[i][j] == 1:
                    pq.heappush(q, [isWater[i][j]-1, i, j])
                
                    isWater[i][j] = -1
        offset = [[0,1],[0,-1],[1,0],[-1,0]]
        
        while len(q) != 0:
            cur = pq.heappop(q)
            
            for i in offset:
                x = cur[1]+i[0]
                y = cur[2]+i[1]
                if x>=size[0] or x<0 or y>=size[1] or y<0:
                    continue
                if isWater[x][y] == 0:
                    isWater[x][y] = cur[0]+1
                    pq.heappush(q, [isWater[x][y], x, y])
        for i in range(size[0]):
            for j in range(size[1]):
                if isWater[i][j] == -1:
                    isWater[i][j] = 0
        return isWater
        
