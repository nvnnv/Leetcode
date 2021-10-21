class Solution:
    def removeDuplicateLetters(self, s: str) -> str:
        q = [s[0]]
        for i in range(len(s)):
            c = s[i]
            if c>q[-1]:
                if c not in q:
                    q.append(c)
            else:
                if s[i] not in q:
                    while len(q) > 0 and q[-1] >= c:
                        if q[-1] not in s[i:]:
                            break
                        else:
                            q.pop(-1)
                    q.append(c)
        x = ''
        for i in q:
            x += i
        return x
                
