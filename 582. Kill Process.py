class Solution:
    def killProcess(self, pid: List[int], ppid: List[int], kill: int) -> List[int]:
        graph = {i:[] for i in ppid}
        for i in range(len(pid)):
            graph[ppid[i]].append(pid[i])
        
        def cascade(i):
            ans = [i]
            if graph.get(i) is None:
                return ans
            for k in graph[i]:
                    ans += cascade(k)
            return ans
        
        return cascade(kill)
            
