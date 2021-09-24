class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        #firstN = -1
        prev = 1
        ans = -1e19
        local = 1
        for i in nums:
            if i == 0:
                prev = 1
                local = 1
                ans = max(ans, 0)
                continue
            if i < 0:
                if prev == 1:
                    prev = local *i
                    ans = max(ans, prev)
                    local = 1
                    continue
                else:
                    local = i*local
            else:
                local = i*local
            #print(local, i, ans)
            ans =  max(ans, prev*local if local < 0 else local)
            #print(local, i, ans)
        return ans
