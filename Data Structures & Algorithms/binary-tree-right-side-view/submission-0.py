# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def rightSideView(self, root: Optional[TreeNode]) -> List[int]:
        ans = []
        if root is None: 
            return ans
        
        q = []
        q.append(root)
        while len(q) != 0:
            n = len(q)
            ans.append(q[n-1].val)
            for i in range(n):
                if q[i].left: 
                    q.append(q[i].left)
                if q[i].right: 
                    q.append(q[i].right)
            
            q = q[n:]
        return ans