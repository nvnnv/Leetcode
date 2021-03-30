    def getFactors(self, n: int) -> List[List[int]]:
        # rootn = int(n**0.5)
        ans = []
        def dfs(m, cur):
            if len(cur) > 0:
                ans.append(cur + [m])
                
            rootm = int(m**0.5)
            for i in range(2, rootm+1):
                if m % i == 0:
                    if len(cur)!= 0:
                        if cur[-1] <= i:
                            cur.append(i)
                            dfs(m//i, cur)
                            cur.pop(-1)
                    else:
                        cur.append(i)
                        dfs(m//i, cur)
                        cur.pop(-1)
        
        dfs(n, [])
        return ans
