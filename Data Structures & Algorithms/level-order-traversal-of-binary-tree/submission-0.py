# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        ans = []
        if root is None: 
            return ans 

        q = []
        q.append(root)
        while len(q) != 0:
            level = []
            n = len(q)
            for i in range(n):
                level.append(q[i].val)
                if q[i].left: 
                    q.append(q[i].left)
                if q[i].right: 
                    q.append(q[i].right)
            
            q = q[n:]
            ans.append(level)
        return ans
