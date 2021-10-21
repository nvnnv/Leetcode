import heapq as pq
class Solution:
    def find132pattern(self, nums: List[int]) -> bool:
        left = [nums[0]]
        for i in range(1, len(nums)):
            left.append(min(nums[i-1], left[-1]))
        right = []
        for i in range(len(nums)-1, 0, -1):
            while len(right) > 0 and nums[i] > right[-1]:
                if left[i] < right[-1]:
                    return True
                right.pop(-1)
            right.append(nums[i])
                
        return False
            
        
