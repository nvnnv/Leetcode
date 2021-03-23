class Solution:
    def __init__(self):
        self.ans = []
        self.used = None
    
    def dfs(self, i, mutation, nums):
        if i == len(nums):
            self.ans.append(mutation.copy())
            return
        
        for j in nums:
            if self.used[j] == 0:
                self.used[j] = 1
                mutation.append(j)
                self.dfs(i+1, mutation, nums)
                mutation.pop(-1)
                self.used[j] = 0
                
    def permute(self, nums: List[int]) -> List[List[int]]:
        self.ans = []
        self.used = {i: 0 for i in nums}
        self.dfs(0, [], nums)
        return self.ans
