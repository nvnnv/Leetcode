    def __init__(self, characters: str, combinationLength: int):
        self.cur_s = characters[0: combinationLength]
        self.s = characters
        self.cl = combinationLength
        self.arr = [i for i in range(self.cl)]

    def next(self) -> str:
        if self.arr[0] > len(self.s) - self.cl + 1:
            return ""
        cur_s = ""
        for i in self.arr:
            cur_s += self.s[i]
        
        # backward update
        j = -1
        k = 0
        for i in range(self.cl-1, -1, -1):
            j = i
            self.arr[i] += 1
            if self.arr[i] == len(self.s) - k:
                k += 1
                continue
            break
        # forward update
        for i in range(j+1, self.cl):
            self.arr[i] = self.arr[i-1] + 1

        return cur_s

    def hasNext(self) -> bool:
        return self.arr[0] < len(self.s) - self.cl + 1
      
        def __init__(self, characters: str, combinationLength: int):
        self.ans = []
        def dfs(i, combinationLength, cur_s):
            if len(cur_s) == combinationLength:
                self.ans.append(cur_s)
                return
            
            pre_s = cur_s
            for j in range(i, len(characters)):
                cur_s += characters[j]
                dfs(j+1, combinationLength, cur_s)
                cur_s = pre_s
        
        dfs(0, combinationLength, "")
        

    def next(self) -> str:
        if self.hasNext():
            return self.ans.pop(0)
        return ""
    def hasNext(self) -> bool:
        return len(self.ans) > 0
