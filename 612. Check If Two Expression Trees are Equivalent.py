# Definition for a binary tree node.
# class Node(object):
#     def __init__(self, val=" ", left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def checkEquivalence(self, root1: 'Node', root2: 'Node') -> bool:
        xxoo = {'a':3, 'b':22,'c':333,'d':444,'e':575,'f':606,'g':177,'h':88, 'i':99,'j':10,'k':11, 'l':102,'m':139,'n':147, 'o':315, 'p':106, 'q':717, 'r':718,'s':1019,'t':209,'u':121,'v':2020,'w':213,'x':240,'y':2345,'z':2677}
        
        def ssum(n):
            if n is None:
                return 0
            
            l = ssum(n.left)
            r = ssum(n.right)
            if xxoo.get(n.val) is not None:
                return xxoo[n.val]
            if n.val == '+':
                return l+r
        
        a = ssum(root1)
        b = ssum(root2)
        return a == b
