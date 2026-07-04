# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def isValidBST(self, root: Optional[TreeNode]) -> bool:
        min_value = float('-inf')
        max_value = float('inf')
        def dfs(root, min_value, max_value):
            if root is None: return True 

            if root.val >= max_value or root.val <= min_value:
                # print("condition got broken", root.val, min_value, max_value)
                return False 

            return dfs(root.left, min_value, root.val) and dfs(root.right, root.val, max_value) 

        
        return dfs(root, min_value, max_value)