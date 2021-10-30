class Solution:
    def merge(self, inte: List[List[int]]) -> List[List[int]]:
        inte.sort(key=lambda x: (x[0],x[1]))
        q = []
        factor = [-1,-1]
        i = 0
        while i < len(inte):
            p = [inte[i][0],inte[i][1]]
            j = i+1
            while j < len(inte):
                if inte[j][0] == inte[j-1][0]:
                    p[1] = max(p[1], inte[j][1])
                    j+=1
                else:
                    break
            if p[0] <= factor[1]:
                factor[1] = max(factor[1], p[1])
            else:
                q.append(factor)
                factor = p
            i = j
        

        q.append(factor)
        q.pop(0)
        return q
