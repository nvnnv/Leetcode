# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def correctBinaryTree(self, root: TreeNode) -> TreeNode:
        q = []
        q.append((root, None))
        v = {}
        v[root.val] = 1
        while len(q) != 0:
            head, f = q.pop(0)
            if head.left is not None:
                q.append((head.left, head))
                v[head.left.val] = 1
            if head.right is not None:
                if v.get(head.right.val) is not None:
                    print(head.val, head.right.val)
                    if f is not None:
                        if f.left == head:
                            f.left = None
                        else:
                            f.right = None
                    return root
                q.append((head.right,head))
                v[head.right.val] = 1
        
        
