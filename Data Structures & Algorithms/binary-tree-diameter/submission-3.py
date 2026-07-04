# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def diameterOfBinaryTree(self, root: Optional[TreeNode]) -> int:
        diameter = 0
        def dfs(root):
            nonlocal diameter

            if not root: return 0
            maxLeft = dfs(root.left)
            maxRight = dfs(root.right)

            diameter = max(diameter, maxLeft + maxRight)

            return 1 + max(maxLeft, maxRight)
        
        dfs(root)
        return diameter

