class BSTIterator:
    
    def dfs(self, node):
        if node is None:
            return []
        
        l = self.dfs(node.left)
        r = self.dfs(node.right)
        return l+[node.val]+r
    
    def __init__(self, root: TreeNode):
        # init
        self.arr = self.dfs(root)
        self.i = -1

    def hasNext(self) -> bool:
        return self.i < len(self.arr)-1

    def next(self) -> int:
        self.i += 1
        if self.i >= len(self.arr):
            return -1
        return self.arr[self.i]

    def hasPrev(self) -> bool:
        return self.i > 0

    def prev(self) -> int:
        self.i -= 1
        if self.i < 0:
            return -1
        return self.arr[self.i]
