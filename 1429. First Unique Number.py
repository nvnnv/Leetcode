class FirstUnique:

    def __init__(self, nums: List[int]):
        self.times = {}
        self.q = []
        for i in nums:
            if i not in self.times:
                self.times[i] = 1
            else:
                self.times[i] +=1
        for i,j in self.times.items():
            if j == 1:
                self.q.append(i)

    def showFirstUnique(self) -> int:
        while len(self.q) > 0:
            i = self.q[0]
            if self.times[i] > 1:
                self.q.pop(0)
            else:
                break

        if len(self.q) == 0:
            return -1
        return self.q[0]

    def add(self, value: int) -> None:
        self.q.append(value)
        if value not in self.times:
            self.times[value] = 1
        else:
            self.times[value] += 1
        #print(value, self.times)
            


# Your FirstUnique object will be instantiated and called as such:
# obj = FirstUnique(nums)
# param_1 = obj.showFirstUnique()
# obj.add(value)
