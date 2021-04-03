    def findContestMatch(self, n: int) -> str:
        nums = [i for i in range(1, n+1)]
        def peel(c, arr):
            if c == 2:
                return '(' + str(arr[0]) + ',' + str(arr[1]) + ')'
            return '(' + peel(c//2, arr[0]) + ',' + peel(c//2, arr[1]) + ')'
        def dfs(c, arr):
            if c == 1:
                return tuple(arr)
            pairs = []
            
            i = 0
            j = len(arr) - 1
            for k in range(c):
                pairs.append((arr[i], arr[j]))
                i += 1
                j -= 1
            return (dfs(c//2, pairs))
        
        x = (dfs(n//2, nums))
        return peel(n, x)
