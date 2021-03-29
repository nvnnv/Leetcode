    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        nums.sort()
        ans =[]
        visited = {}
        for i in nums:
            if visited.get(i) is None:
                visited[i] = 0
            visited[i] += 1
            
        def dfs(i, cur):
            ans.append(cur.copy())
            if i == len(nums):
                return 
            
            last = -11
            for j in range(i, len(nums)):
                if last != nums[j]:
                    #visited[nums[j]] -= 1
                    cur.append(nums[j])
                    dfs(j+1, cur)
                    cur.pop(-1)
                    #visited[nums[j]] += 1
                last = nums[j]
            
        dfs(0, [])
        return ans
