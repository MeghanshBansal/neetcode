# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def lowestCommonAncestor(self, root: TreeNode, p: TreeNode, q: TreeNode) -> TreeNode:
        if root is None or p is None or q is None: return None 
        if root is not None and root.val == p.val: return p 
        if root is not None and root.val == q.val: return q 

        left = self.lowestCommonAncestor(root.left, p, q)
        right = self.lowestCommonAncestor(root.right, p, q)

        if left is not None and right is not None: return root 
        if left is not None and right is None: return left 
        if left is None and right is not None: return right 

        else: return None 