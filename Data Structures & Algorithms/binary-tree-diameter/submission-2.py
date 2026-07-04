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
            if root is None: 
                return 0

            left_d = dfs(root.left)
            right_d = dfs(root.right)

            diameter = max(diameter, left_d + right_d)

            return max(left_d, right_d) + 1

        dfs(root)
        return diameter