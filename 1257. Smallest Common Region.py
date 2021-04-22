class Solution:
    def findSmallestRegion(self, regions: List[List[str]], region1: str, region2: str) -> str:
        if len(regions) == 0:
            return ''
        
        anti_t = {}
        for items in regions:
            for i in items[1:]:
                # impossible that a city belong to two states
                anti_t[i] = items[0]
        
        trace1 = []
        trace2 = []
        def dfs(n, trace):
            trace.append(n)
            if anti_t.get(n) is None:
                return
            dfs(anti_t[n], trace)
        
        dfs(region1, trace1)
        dfs(region2, trace2)
        trace2 = {i:1 for i in trace2}
        for i in trace1:
            if trace2.get(i) is not None:
                return i
        return ''
        
            
            
            
        
