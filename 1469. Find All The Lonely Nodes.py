class Solution:
    def getLonelyNodes(self, root: TreeNode) -> List[int]:
            if root is None:
                return []
            
            a = []
            if root.left is None and root.right is not None:
                a.append(root.right.val)
            if root.right is None and root.left is not None:
                a.append(root.left.val)
            
            a += self.getLonelyNodes(root.left)
            a += self.getLonelyNodes(root.right)
            
            return a
