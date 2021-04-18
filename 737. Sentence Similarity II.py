class Solution:
    def areSentencesSimilarTwo(self, words1: List[str], words2: List[str], pairs: List[List[str]]) -> bool:
        if len(words1) != len(words2):
            return False
        
        unionfind = {}
        def find(i):
            if unionfind.get(i) is None:
                unionfind[i] = i
                return i
            while i != unionfind[i]:
                i = unionfind[i]
            return i
        
        def unify(a, b):
            fa = find(a)
            fb = find(b)
            unionfind[fb] = fa
        
        for p in pairs:
            unify(p[0], p[1])
        
        for i in range(len(words1)):
            if find(words1[i]) != find(words2[i]):
                return False
        return True
