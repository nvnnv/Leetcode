    def uniquePathsIII(self, grid: List[List[int]]) -> int:
        size = (len(grid), len(grid[0]))
        if size[0] == size[1] == 1:
            return 0
        
        obstacles = 0
        for i in range(size[0]):
            for j in range(size[1]):
                if grid[i][j] == 1:
                    start_point = (i, j)
                if grid[i][j] == 2:
                    end_point = (i, j)
                if grid[i][j] == -1:
                    obstacles += 1
        must_steps = size[0]*size[1] - obstacles - 2
        visited = [[0 for j in range(size[1])] for j in range(size[0])]
        offset = [[1,0],[-1,0],[0,1],[0,-1]]
        c = [0]
        
        def dfs(cur_p, end_p, must_s, cur_s):
            if  cur_p == end_p: 
                if cur_s == must_s:
                    c[0] += 1
                return
            
            #print(cur_p, cur_s)
            visited[cur_p[0]][cur_p[1]] = 1
            for i, j in offset:
                next_p = (cur_p[0]+i, cur_p[1]+j)
                if next_p[0] < 0 or next_p[0] >= size[0] or next_p[1] >= size[1] or next_p[1] < 0:
                    continue
                if visited[next_p[0]][next_p[1]] == 1 or grid[next_p[0]][next_p[1]] == -1:
                    continue
                dfs(next_p, end_p, must_s, cur_s+1)
            visited[cur_p[0]][cur_p[1]] = 0
            
        dfs(start_point, end_point, must_steps, -1)
        return c[0]
