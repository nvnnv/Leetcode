
class Solution:
    def frequencySort(self, s: str) -> str:
        f = {}
        for i in s:
            if i not in f:
                f[i] = 0
            f[i] +=1
        ff = sorted(f.items(), key=lambda x: x[1], reverse=True)
        xs = ''
        for i,j in ff:
            for k in range(j):
                xs += i
        return xs
