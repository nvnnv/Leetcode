    def wordPatternMatch(self, pattern: str, s: str) -> bool:
        if pattern is None or s is None:
            return False
        if len(pattern) == 0 or len(s) == 0:
            return False
        if len(pattern) == 1:
            return True
        
        v1 = {}
        v2 = {}
        def dfs(i, substr, pos):
            if i == len(pattern):
                # check pattern
                return True
            if i == len(pattern)-1:
                sub = s[pos:]
                #print(sub, pattern[i], v1.get(sub), v2.get(pattern[i]), substr, 2)
                if (v1.get(sub) == pattern[i] and v2.get(pattern[i]) == sub) or (v1.get(sub) is None and v2.get(pattern[i]) is None):
                    v1[sub] = pattern[i]
                    v2[pattern[i]] = sub
                    substr.append(s[pos:])
                    if dfs(i+1, substr, -1):
                        return True
                    substr.pop(-1)
                    v1[sub] = None
                    v2[pattern[i]] = None
            else:
                for j in range(pos+1, len(s)):
                    sub = s[pos : j]
                    #print(sub, pattern[i], v1.get(sub), v2.get(pattern[i]), substr, 1 )
                    if (v1.get(sub) == pattern[i] and v2.get(pattern[i]) == sub) or (v1.get(sub) is None and v2.get(pattern[i]) is None):
                        v1[sub] = pattern[i]
                        v2[pattern[i]] = sub
                        substr.append(s[pos: j])
                        if dfs(i+1, substr, j):
                            return True
                        substr.pop(-1)
                        v1[sub] = None
                        v2[pattern[i]] = None
            return False
        
        return dfs(0, [], 0)
