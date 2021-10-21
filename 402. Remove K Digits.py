class Solution:
    def removeKdigits(self, num: str, k: int) -> str:
        if len(num) == k:
            return '0'
        x = 0
        q = []
        p = {}
        ans = ''
        for i in range(len(num)):
            while len(q)>0 and int(num[q[-1]]) > int(num[i]) and x < k:
                p[q.pop(-1)] = 1
                x += 1
            q.append(i)

        while x < k:
            q.pop(-1)
            x+=1
        for i in range(len(q)):
            if num[q[i]] != '0':
                s = ''
                #print(i, q)
                for j in q[i:]:
                    s += num[j]
                return s
        return '0'
