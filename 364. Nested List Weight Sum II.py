class Solution:
    def depthSumInverse(self, nestedList: List[NestedInteger]) -> int:
        if nestedList is None or len(nestedList) == 0:
            return 0
        
        def maxDeep(integer, d):
            if integer.isInteger():
                return d
            
            dx = 0
            for i in integer.getList():
                dx = max(maxDeep(i, d+1), dx)
            
            return dx
            
        
        def dfs(integer, d):
            if integer.isInteger():
                return (maxD[0] - d + 1) * integer.getInteger()
            
            s = 0
            for i in integer.getList():
                s += dfs(i, d+1)
            
            return s
        
        maxD = [0]
        for i in nestedList:
            maxD[0] = max(maxDeep(i, 1), maxD[0])
        s = 0
        for i in nestedList:
            s += dfs(i, 1)
        
        return s
