    def findShortestSubArray(self, nums):
        degree = 0
        d_num = []
        flag = {i:0 for i in nums}
        for i in nums:
            flag[i] += 1
            degree = max(degree, flag[i])
        for (i,j) in flag.items():
            if j == degree:
                d_num.append(i)
        ans = 500000
        for i in d_num:
            _start = nums.index(i)
            _end = len(nums)-1 -  nums[::-1].index(i)
            ans = min(ans, _end-_start+1)
        return ans
  
  
