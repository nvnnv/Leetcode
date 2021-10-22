class Solution:
    def numberOfWeakCharacters(self, p: List[List[int]]) -> int:
        p.sort(key=lambda x: (x[0],x[1]))
        a = 0
        f = {}
        pp = []
        for i in range(len(p)):
            if p[i][0] not in f:
                f[p[i][0]] = []
                pp.append(p[i][0])
            f[p[i][0]].append(p[i][1])
        
        ma = max(f[pp[-1]])
        
        for i in range(len(pp)-2, -1, -1):
            xl = f[pp[i]]
            m = ma
            for i in xl:
                if i < ma:
                    a+=1
                m = max(m, i)
            ma = m
            
        return a
