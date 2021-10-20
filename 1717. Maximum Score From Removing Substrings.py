class Solution:
    def maximumGain(self, s: str, x: int, y: int) -> int:
        if x > y:
            df = ['ab', 'ba']
            p = [x, y]
        else:
            df = ['ba', 'ab']
            p = [y, x]
        
        q = []
        x = s
        ans =0
        for i in range(len(df)):
            for j in range(len(x)):
                q.append(x[j])
                while len(q) > 1:
                    if ''.join(q[-2:]) == df[i]:
                        ans += p[i]
                        q.pop(-1)
                        q.pop(-1)
                    else:
                        break
            x = ''.join(q)
            q = []
        
        return ans
                
