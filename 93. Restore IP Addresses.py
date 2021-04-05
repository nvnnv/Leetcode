class Solution:
    def restoreIpAddresses(self, s: str) -> List[str]:
        if s is None or len(s) < 4:
            return []
        
        ans = []
        def dfs(i, combination, pos):
            if i == 4:
                ans.append(combination)
                return
            
            pres = combination
            if i == 3:
                sub = s[pos:]
                if (len(sub) > 1 and sub[0] == '0') or sub == '':
                    return
                if int(sub) > 255:
                    return
                combination += sub
                dfs(i+1, combination, -1)
                combination = pres
            else:
                for j in range(pos+1, len(s)):
                    sub = s[pos:j]
                    if len(sub) > 1 and sub[0] == '0':
                        return
                    if int(sub) > 255:
                        return
                    combination += sub + '.'
                    dfs(i+1, combination, j)
                    combination = pres
            
        dfs(0, '', 0)
        return ans
