    def findDisappearedNumbers(self, nums):
        for (i, val) in enumerate(nums):
            if val > 0:
                if nums[val-1] > 0:
                    nums[val-1] = -nums[val-1]
            else:
                if nums[abs(val)-1] > 0:
                    nums[abs(val)-1] = -nums[abs(val)-1]
        ans = []
        for i in range(1, len(nums)+1):
            if nums[i-1] > 0:
                ans.append(i)
        return ans
