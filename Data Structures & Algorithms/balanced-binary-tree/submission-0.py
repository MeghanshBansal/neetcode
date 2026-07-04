# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def isBalanced(self, root: Optional[TreeNode]) -> bool:
        res = True
        def dfs(root):
            nonlocal res
            if not root: 
                return 0
            
            leftheight = dfs(root.left)
            rightheight = dfs(root.right)

            if abs(leftheight - rightheight) > 1: 
                res = False
                return 0

            return 1 + max(leftheight, rightheight)
        
        dfs(root)
        return res

            

            