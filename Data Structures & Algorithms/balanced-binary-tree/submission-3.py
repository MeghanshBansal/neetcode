# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def isBalanced(self, root: Optional[TreeNode]) -> bool:
        answer = True
        def dfs(root):
            nonlocal answer
            if not root: return 0

            LH = dfs(root.left)
            RH = dfs(root.right)

            if abs(LH - RH) > 1:
                answer = False
            
            return 1 + max(LH, RH)
        dfs(root)
        return answer