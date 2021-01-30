  # 5548ms
  def findSubsequences(self, nums: List[int]) -> List[List[int]]:
        ans = []
        def dfs(sub, i):
            sub.append(nums[i])
            if len(sub) >= 2:
                if sub not in ans:
                    ans.append(sub.copy())
            for j in range(i+1, len(nums)):
                if nums[j] >= nums[i]:
                    dfs(sub, j)
            sub.pop()
        for i in range(len(nums)):
            dfs([], i)
        return ans
   # 212ms
      def findSubsequences(self, nums: List[int]) -> List[List[int]]:
        ans = []
        def dfs(sub, i, val):
            if len(sub) >= 2:
                ans.append(sub.copy())
            
            used = set()
            for j in range(i, len(nums)):
                if nums[j] >= val and nums[j] not in used:
                    used.add(nums[j])
                    sub.append(nums[j])
                    dfs(sub, j+1, nums[j])
                    sub.pop()
        dfs([], 0, -200)
        return ans
