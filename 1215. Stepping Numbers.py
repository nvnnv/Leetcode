    def countSteppingNumbers(self, low: int, high: int) -> List[int]:
        ans = []
        def dfs(d, p):
            if d < 0 or d >= 10:
                return
            if p > high:
                return
            if low<=p<=high:
                ans.append(p)
            

            dfs(d-1, p*10 + (d-1))
            dfs(d+1, p*10 + (d+1))
        
        
        for i in range(1, 10):
            dfs(i, i)
        if low == 0:
            ans.append(0)
        ans.sort()
        return ans
