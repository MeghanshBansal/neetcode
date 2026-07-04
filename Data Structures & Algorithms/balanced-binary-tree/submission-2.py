# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def isBalanced(self, root: Optional[TreeNode]) -> bool:
        is_balanced = True
        def dfs(root):
            nonlocal is_balanced
            if root is None: 
                return 0

            left_d = dfs(root.left)
            right_d = dfs(root.right)

            if abs(left_d - right_d) > 1: 
                is_balanced = False 

            return max(left_d, right_d) + 1

        dfs(root)
        return is_balanced