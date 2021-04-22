# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def str2tree(self, s: str) -> TreeNode:
        if s == '':
            return None
        def reconstruct(s):
            if s == '':
                return None
            if s[0] == '-':
                if s[1:].isdigit():
                    return TreeNode(int(s))
            else:
                if s.isdigit():
                    return TreeNode(int(s))
            
            x = ''
            i = 0
            while s[i] != '(':
                x+=s[i]
                i+=1
            node = TreeNode(int(x))
            j = i
            left = 0
            right = 0
            while j < len(s):
                if s[j] == '(':
                    left+=1
                if s[j] == ')':
                    right+=1
                j+=1
                if left == right:
                    break
            node.left = reconstruct(s[i+1:j-1])
            i = j
            left = 0
            right = 0
            while j < len(s):
                if s[j] == '(':
                    left+=1
                if s[j] == ')':
                    right+=1
                j+=1
                if left == right:
                    break
            node.right = reconstruct(s[i+1:j-1])
            return node
        return reconstruct(s)
                
