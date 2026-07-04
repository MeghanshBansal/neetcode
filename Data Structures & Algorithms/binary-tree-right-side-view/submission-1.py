# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def rightSideView(self, root: Optional[TreeNode]) -> List[int]:
        if root is None: 
            return []
        ans = []
        q = list()
        q.append(root)
        while len(q) != 0:
            ans.append(q[-1].val)
            n = len(q) 
            for i in range(n):
                node = q.pop(0)
                if node.left: q.append(node.left)
                if node.right: q.append(node.right)
        return ans
