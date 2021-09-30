class Solution:
    def asteroidCollision(self, a: List[int]) -> List[int]:
        q = []
        for i in a:
            if i < 0:
                f = 0
                while len(q) > 0:
                    if q[-1] > 0:
                        if abs(q[-1]) < abs(i):
                            q.pop(-1)
                            continue
                        if abs(q[-1]) == abs(i):
                            q.pop(-1)
                            f=1
                            break
                        if abs(q[-1]) > abs(i):
                            f=1
                            break
                    break
                if f==0:
                    q.append(i)
            else:
                q.append(i)
        return q
