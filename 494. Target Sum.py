        def findTargetSumWays(self, nums, S: int) -> int:
            dp = {}
            def dfs(level, target):
                if level == len(nums):
                    if target == S:
                        return 1
                    return 0
                key = (level, target)
                if key not in dp:
                    dp[key] = dfs(level+1, target+nums[level]) + dfs(level+1, target-nums[level])

                return dp[key]

            dp1 = {}
            dp1[nums[0]] = 1
            if dp1.get(-nums[0]) is None:
                dp1[-nums[0]] = 1
            else:
                dp1[-nums[0]] += 1
            for i in nums[1:]:
                temp = {}
                for j in dp1.keys():
                    if temp.get(j+i) is None:
                        temp[j+i] = 0
                    temp[j+i] += dp1[j]
                    if temp.get(j-i) is None:
                        temp[j-i] = 0
                    temp[j-i] += dp1[j]
                dp1 = temp
            return dp1.get(S, 0)
            #return dfs(0, 0)
