class Solution:
    def findLengthOfShortestSubarray(self, arr: List[int]) -> int:
        q = []
        ans = len(arr) - 1
        j = len(arr) - 1
        while j >= 1 and arr[j-1] <= arr[j]:
            j-=1
        ans = min(ans, j)
        if ans == 0 :
            return 0
        for i in range(len(arr)):
            if i-1>=0 and arr[i-1] > arr[i]:
                break
            while j<len(arr) and arr[i] > arr[j]:
                j+=1
            ans = min(ans, j-i-1)
        if ans == -1:
            return 0
        return ans
