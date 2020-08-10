    def canThreePartsEqualSum(self, A):
        addition = sum(A)
        mod = addition%3
        if mod != 0:
            return False
        partSum = addition/3
        temp = 0
        j = 0
        k = 0
        for (index, i) in enumerate(A):
            temp += i
            if temp == partSum:
                temp = 0
                j += 1
                if j == 2:
                    if index+1 < len(A):
                        rest = sum(A[index+1:])
                        if rest == partSum:
                            j += 1
                    break
        if j == 3:
            return True
        else:
            return False
