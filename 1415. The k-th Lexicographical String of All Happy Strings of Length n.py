    def getHappyString(self, n: int, k: int) -> str:
        if n <= 0:
            return ""
        
        s = ['a','b','c']
        cur_s = [""]
        ans = [""]
        c = [0]
        def dfs(i):
            if len(cur_s[0]) > 1 and cur_s[0][-1] == cur_s[0][-2]:
                return
            if i == n:
                c[0] += 1
                if c[0] == k:
                    ans[0] = cur_s[0]
                return
            
            cc = cur_s[0]
            for ch in s:
                cur_s[0] += ch
                dfs(i+1)
                cur_s[0] = cc
                if len(ans[0]) > 0:
                    return
            
        dfs(0)
        return ans[0]
