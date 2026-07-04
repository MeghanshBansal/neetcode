# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def isSameTree(self, p: Optional[TreeNode], q: Optional[TreeNode]) -> bool:
        res = True
        def dfs(p, q):
            nonlocal res
            if p is None and q is None: 
                return 
            if p is None: 
                res = False
                return 
            if q is None: 
                res = False
                return 
            
            if p.val != q.val:
                res = False
                return 

            dfs(p.left, q.left)
            dfs(p.right, q.right)
            return 

        dfs(p, q)
        return res