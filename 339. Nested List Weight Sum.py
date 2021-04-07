
class Solution:
    def depthSum(self, nestedList: List[NestedInteger]) -> int:
        if nestedList is None or  len(nestedList) == 0:
            return 0
        
        def dfs(nestedInteger, d):
            if nestedInteger.isInteger():
                return nestedInteger.getInteger() * d
            
            s = 0
            for i in nestedInteger.getList():
                s += dfs(i, d+1)
            
            return s
        
        s = 0
        for i in nestedList:
            s += dfs(i, 1)
        
        return s
