class Solution:
    def sumSubarrayMins(self, arr: List[int]) -> int:
        q = []
        left = []
        right = []
        for i in arr:
            l = 1
            while len(q) > 0 and q[-1][0] > i:
                l+=q[-1][1]
                q.pop(-1)
            q.append([i, l])
            left.append(l)
        q = []
        for j in arr[::-1]:
            l= 1
            while len(q) > 0 and q[-1][0] >= j:
                l += q[-1][1]
                q.pop(-1)
            q.append([j,l])
            right.append(l)
        right = right[::-1]
        ans = 0
        mod = 1e9+7
        for i in range(len(arr)):
            ans = (ans + left[i]*arr[i]*right[i])%mod
        return int(ans)
            
