class Solution:
    
    def __init__(self):
        self.ans = []
        
    def dfs(self, i, cur_s, S):
        if i == len(S):
            self.ans.append(cur_s)
            return

        if S[i].isdigit():
            self.dfs(i+1, cur_s+S[i], S)
        else:
            self.dfs(i+1, cur_s+S[i].lower(), S)
            self.dfs(i+1, cur_s+S[i].upper(), S)

        
    def letterCasePermutation(self, S: str) -> List[str]:
        self.ans = []
        self.dfs(0, "", S)
        return self.ans
