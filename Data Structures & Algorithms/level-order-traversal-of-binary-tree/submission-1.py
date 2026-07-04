# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        ans = []
        if root is None: return ans 
        q = list()
        q.append(root)

        while len(q) != 0: 
            n = len(q)
            l = []
            for i in range(n):
                node = q.pop(0)
                l.append(node.val)
                if node.left: q.append(node.left)
                if node.right: q.append(node.right)

            ans.append(l)
        
        return ans 
