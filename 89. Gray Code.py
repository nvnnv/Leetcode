  // 3892ms
  def __init__(self):
        self.visited = []
        self.ans = []
        self.f = 0
    def toNum(self, a):
        base = 1
        s = 0
        for i in a[::-1]:
            s += i*base
            base *= 2
        return s
    def dfs(self, cur_a, i, n):
        s = self.toNum(cur_a)
        if self.visited[s] == 1:
            return
        if i == n:
            self.f = 1
            return
        
        self.visited[s] = 1
        self.ans.append(s)
        for i in range(len(cur_a)):
            cur_a[i] = 0 if cur_a[i] == 1 else 1
            self.dfs(cur_a, i+1, n)
            if self.f == 1:
                return
            cur_a[i] = 0 if cur_a[i] == 1 else 1
        
    def grayCode(self, n: int) -> List[int]:
        self.ans = []
        m = 2**n
        self.visited = [0 for i in range(m)]
        self.dfs([0 for i in range(n)], 0, m)
        return self.ans
        
        
//   92ms
def grayCode(self, n: int) -> List[int]:
        s = [0, 1]
        for i in range(1, n):
            nex = [j + (1<<i) for j in reversed(s)]
            s += nex
        return s
