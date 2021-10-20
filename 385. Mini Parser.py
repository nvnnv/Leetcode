# """
# This is the interface that allows for creating nested lists.
# You should not implement it, or speculate about its implementation
# """
#class NestedInteger:
#    def __init__(self, value=None):
#        """
#        If value is not specified, initializes an empty list.
#        Otherwise initializes a single integer equal to value.
#        """
#
#    def isInteger(self):
#        """
#        @return True if this NestedInteger holds a single integer, rather than a nested list.
#        :rtype bool
#        """
#
#    def add(self, elem):
#        """
#        Set this NestedInteger to hold a nested list and adds a nested integer elem to it.
#        :rtype void
#        """
#
#    def setInteger(self, value):
#        """
#        Set this NestedInteger to hold a single integer equal to value.
#        :rtype void
#        """
#
#    def getInteger(self):
#        """
#        @return the single integer that this NestedInteger holds, if it holds a single integer
#        Return None if this NestedInteger holds a nested list
#        :rtype int
#        """
#
#    def getList(self):
#        """
#        @return the nested list that this NestedInteger holds, if it holds a nested list
#        Return None if this NestedInteger holds a single integer
#        :rtype List[NestedInteger]
#        """

class Solution:
    def deserialize(self, s: str) -> NestedInteger:
        op = {'0','1','2','3','4','5','6','7','8','9', '-'}
        if s[0] != '[':
            return NestedInteger(str(s))
        def dfs(p):
            e = NestedInteger()
            while len(p)>0 and p[0] != ']':
                if p[0] == '[':
                    q.pop(0)
                    e.add(dfs(p))
                else:
                    x = ''
                    if len(p) > 0 and p[0] == ',':
                        p.pop(0)
                    while len(p) > 0 and p[0] in op:
                        x += p[0]
                        p.pop(0)
                    if len(x)> 0 and (x[0] == '-' or x.isnumeric()):
                        e.add(NestedInteger(int(x)))
                    if len(p) > 0 and p[0] == ',':
                        p.pop(0)
                
            if len(q) > 0:
                p.pop(0)
            return e
        q = []
        for c in s:
            q.append(c)
        q.pop(0)
        return dfs(q)
