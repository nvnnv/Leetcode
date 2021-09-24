class Solution:
    def checkValidString(self, s: str) -> bool:
        
        def dfs(i, count, dp):
            if i == len(s):
                return count == 0
            if (i, count) in dp:
                return dp[(i, count)]
            
            if s[i] == '(':
                f = dfs(i+1, count+1, dp)
            if s[i] == ')':
                if count > 0:
                    f = dfs(i+1, count-1, dp)
                else:
                    return False
            if s[i] == '*':
                f = dfs(i+1, count + 1, dp) | dfs(i+1, count, dp)
                if count > 0:
                    f = f | dfs(i+1, count-1, dp)
            dp[(i, count)] = f
            return f

        return dfs(0,0, {})
            
