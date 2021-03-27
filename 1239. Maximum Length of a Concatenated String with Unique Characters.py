    def maxLength(self, arr: List[str]) -> int:
        l = [0]
        
        fitler = []
        for s in arr:
            v = {}
            for c in s:
                if v.get(c) is None:
                    v[c] = 1
                else:
                    break
            else:
                fitler.append(s)
        arr = fitler
        
        def dfs(i, s):
            l[0] = max(len(s), l[0])
            
            for j in range(i, len(arr)):
                for c in arr[j]:
                    if c in s:
                        break
                else:
                    dfs(j, s+arr[j])
                    s[:len(s)-len(arr[j])]
        
        dfs(0, "")
        return l[0]
