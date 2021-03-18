class Solution:
    def makesquare(self, nums: List[int]) -> bool:
        if len(nums) <= 0:
            return False
        limit = sum(nums)
        if limit % 4 != 0:
            return False
        limit = limit / 4
        visited = [0 for i in range(len(nums))]
        nums.sort(reverse=True)
        if nums[0] > limit:
            return False
        
        def dfs(cur, group, s, l):
            if group == 4:
                return True
            if s > l:
                return False
            if s == l:
                return dfs(0, group+1, 0, l)
            
            last_value = -1
            for i in range(cur, len(nums)):
                if visited[i] != 1 and nums[i] != last_value:
                    visited[i] = 1
                    last_value = nums[i]
                    if dfs(cur+1,  group, s+nums[i], l):
                        return True
                    visited[i] = 0
            return False
        
        return dfs(0, 0, 0, limit)
