class Solution:
    def parseTernary(self, expression: str) -> str:
        s = []
        i = len(expression)-1
        while i >= 0:
            a = ''
            while i >= 0 and expression[i] != ':' and expression[i] != '?':
                a += expression[i]
                i -= 1
            if a != '':
                s.append(a[::-1])

            if i >= 0 and expression[i] == '?':
                i -= 1
                if expression[i] == 'T' or expression[i] == 'F':
                    x = s.pop(-1)
                    y = s.pop(-1)
    
                    if expression[i] == 'T':
                        s.append(x)
                    else:
                        s.append(y)
                    i -= 1

            if expression[i] == ':':
                i -= 1

        return s.pop(-1)
