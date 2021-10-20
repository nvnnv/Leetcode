class Solution:
    def maxSumMinProduct(self, nums: List[int]) -> int:
        presum = []
        s = 0
        mod = 1e9+7
        for i in nums:
            s = s+i
            presum.append(s)
        
        q = []
        ans = 0
        nums.append(0)
        for i in range(len(nums)):
            while len(q)>0 and nums[q[-1]] >= nums[i]:
                a = q.pop(-1)
                right = i-1
                left = q[-1]+1 if len(q) > 0 else 0
                ans = max(ans, nums[a]*(presum[right]-(presum[left-1] if left != 0 else 0)))
                #print(ans, right, left, nums[a])
            q.append(i)
        
        return ans%(10**9+7)
