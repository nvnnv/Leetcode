class Solution:
    def permuteUnique(self, nums: List[int]) -> List[List[int]]:
        ans = []
        visited = {i: 0 for i in nums}
        for i in nums:
            visited[i] += 1
        
        def dfs(cur_a):
            if len(cur_a) == len(nums):
                ans.append(cur_a.copy())
                return
            
            iv = {}
            for i in nums:
                if visited[i] != 0 and iv.get(i) is None:
                    visited[i] -= 1
                    cur_a.append(i)
                    dfs(cur_a)
                    cur_a.pop(-1)
                    visited[i] += 1
                iv[i] = 1
        
        dfs([])
        return ans
