# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Codec:

    def serialize(self, root):
        """Encodes a tree to a single string.
        
        :type root: TreeNode
        :rtype: str
        """
        level = []
        def dfs(node, c):
            if c>=len(level):
                level.append([])
            if node is None:
                level[c].append('null')
                return
            
            level[c].append(node.val)
            dfs(node.left, c+1)
            dfs(node.right, c+1)
        
        dfs(root, 0)
        s = ''
        for i in range(len(level)):
            for j in range(len(level[i])):
                s += str(level[i][j]) + ' '
            s = s[:-1]
            s += ','
        s = s[:-1]
        return s

    def deserialize(self, data):
        """Decodes your encoded data to tree.
        
        :type data: str
        :rtype: TreeNode
        """
        level = data.split(',')
        if level[0] == 'null':
            return None
        
        root = TreeNode(int(level[0]))
        q = [root]
        for c in level[1:]:
            ns = c.split(' ')
            p = []
            while len(q) > 0:
                h = q.pop(0)
                a, b = ns.pop(0), ns.pop(0)
                if a != 'null':
                    h.left = TreeNode(int(a))
                    p.append(h.left)
                if b != 'null':
                    h.right = TreeNode(int(b))
                    p.append(h.right)
            q = p
        return root
                    
        
        

# Your Codec object will be instantiated and called as such:
# ser = Codec()
# deser = Codec()
# ans = deser.deserialize(ser.serialize(root))
