    def colorBorder(self, grid, r0: int, c0: int, color: int):
        offset = [(0,1),(0,-1),(1,0),(-1,0)]
        size = (len(grid), len(grid[0]))
        borders = {}
        """
        def dfs(cur_pos, visited):
            if visited.get(cur_pos) is not None:
                return
            visited[cur_pos] = 1
            for i in offset:
                next_pos = (cur_pos[0]+i[0], cur_pos[1]+i[1])
                if next_pos[0] >= 0 and next_pos[0] < size[0] and next_pos[1] >= 0 and next_pos[1] < size[1]:
                    if grid[next_pos[0]][next_pos[1]] != grid[cur_pos[0]][cur_pos[1]]:
                        # border
                        borders[cur_pos] = 1
                    else:
                        dfs(next_pos, visited)
                else:
                    borders[cur_pos] = 1
        dfs((r0,c0), {})
        """

        q = queue.Queue()
        q.put((r0, c0))
        visited = {}
        while(not q.empty()):
            cur_pos = q.get()
            visited[cur_pos] = 1
            for i in offset:
                next_pos = (cur_pos[0]+i[0], cur_pos[1]+i[1])
                if visited.get(next_pos) is not None:
                    continue
                if next_pos[0] >= 0 and next_pos[0] < size[0] and next_pos[1] >= 0 and next_pos[1] < size[1]:
                    if grid[next_pos[0]][next_pos[1]] != grid[cur_pos[0]][cur_pos[1]]:
                        # border
                        borders[cur_pos] = 1
                    else:
                        q.put(next_pos)
                else:
                    borders[cur_pos] = 1


        for i in borders.keys():
            grid[i[0]][i[1]] = color
        return grid
