    def numTilePossibilities(self, tiles: str) -> int:
        if len(tiles) == 0:
            return 0
        
        visited = {c: 0 for c in tiles}
        for c in tiles:
            visited[c] += 1
            
        ans = {}
        def dfs(cur_s, i, n):
            if i == n:
                ans[cur_s] = 1
                return
            
            for c in visited.keys():
                if visited[c] != 0:
                    visited[c] -= 1
                    dfs(cur_s+c, i+1, n)
                    visited[c] += 1
        
        for i in range(1, len(tiles)+1):
            dfs("", 0, i)
        
        return len(ans)
