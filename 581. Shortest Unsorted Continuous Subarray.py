class Solution:
    def findUnsortedSubarray(self, nums: List[int]) -> int:
        q = []
        l = len(nums)
        # front
        for i in range(len(nums)):
            while len(q) > 0 and nums[q[-1]] > nums[i]:
                l = min(l, q.pop(-1))
            q.append(i)
        
        q = []
        r = 0
        for i in range(len(nums)-1, -1, -1):
            while len(q) > 0 and nums[q[-1]] < nums[i]:
                r = max(r, q.pop(-1))
            q.append(i)
        
        if l > r:
            return 0
        return r - l + 1

class Solution:
    def findUnsortedSubarray(self, nums: List[int]) -> int:
        xo = [i for i in nums]
        xo.sort()
        left = 0
        for i in range(len(nums)):
            if xo[i] != nums[i]:
                left = i
                break
        right = 0
        for i in range(len(nums)-1, -1, -1):
            if xo[i] != nums[i]:
                right = i
                break
        
        if right==0 and left == 0:
            return 0
        else:
            return right -left+1
