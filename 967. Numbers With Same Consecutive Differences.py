    def numsSameConsecDiff(self, n: int, k: int):
        ans = []
        for i in range(1, 10):
            sub = [i]
            for j in range(1, n):
                temp = []
                for x in sub:
                    base = x % 10
                    if k != 0:
                        if base - k >=0:
                            temp.append(x * 10 + (base - k))
                        if base + k < 10:
                            temp.append(x * 10 + (base + k))
                    else:
                        temp.append(x * 10 + base)
                sub = temp
            ans += sub
        return ans
