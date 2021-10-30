class Solution:
    def searchMatrix(self, ma: List[List[int]], target: int) -> bool:
        for r in range(len(ma)):
            i,j = 0, len(ma[r])-1
            while i<=j:
                m = int((i+j)//2)
                if ma[r][m] > target:
                    j= m-1
                if ma[r][m] < target:
                    i = m+1
                if ma[r][m] == target:
                    return True
        return False
