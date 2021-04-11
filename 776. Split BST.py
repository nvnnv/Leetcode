    def splitBST(self, root: TreeNode, V: int) -> List[TreeNode]:
        if root is None:
            return [None, None]
        
        if root.val <= V:
            left, right = self.splitBST(root.right, V)
            root.right = left
            return [root, right]
        else:
            left, right = self.splitBST(root.left, V)
            root.left = right
            return [left, root]
