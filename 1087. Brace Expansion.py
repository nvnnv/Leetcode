class Solution:
    def expand(self, s: str) -> List[str]:
        options = []
        f = 0
        j = 0
        _s = ""
        for i in range(len(s)):
            if s[i] == '{':
                f = 1
                continue
            if s[i] == '}':
                f = 0
                j += 1
                _s += " "
                continue
            if f == 0:
                _s += s[i]
            else:
                if len(options) == j:
                    options.append([])
                if s[i].isalpha():
                    options[j].append(s[i])
                
        ans = []
        def dfs(string, blank_c):
            if blank_c == len(options):
                ans.append(string)
                return
            
            for i in range(len(string)):
                if string[i] == ' ':
                    for j in options[blank_c]:
                        dfs(string[:i] + j + string[i+1:], blank_c+1)
                    break
        dfs(_s, 0)
        ans.sort()
        return ans
