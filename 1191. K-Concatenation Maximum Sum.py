class Solution:
    def kConcatenationMaxSum(self, arr: List[int], k: int) -> int:
        a1 = arr
        a2 = arr*2
        lm = m1=m2=0
        for i in a1:
            lm = max(lm+i, i)
            m1 = max(m1, lm)
        
        if k == 1:
            return m1
        
        lm = 0
        for i in a2:
            lm = max(lm+i, i)
            m2 = max(m2, lm)
        mod = 1e9+7
        return int(max(m1, m2, (k-2)*sum(arr) + m2) % mod)
