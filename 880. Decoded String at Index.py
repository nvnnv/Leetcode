class Solution:
    def decodeAtIndex(self, s: str, k: int) -> str:
        l = 0
        for i in s:
            if i.isdigit():
                l*=int(i)
            else:
                l+=1
        
        for i in s[::-1]:
            k= k % l
            if k == 0 and i.isalpha():
                return i
            if i.isdigit():
                l = l//int(i)
            else:
                l -= 1
        
