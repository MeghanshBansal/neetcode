# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def goodNodes(self, root: TreeNode) -> int:
        count = 0
        greatest = float('-inf')
        if root is None: return ans 
        def dfs(root, greatest):
            nonlocal count
            if root is None: return 

            if root.val >= greatest: 
                count += 1
            
            greatest = max(root.val, greatest)
            dfs(root.left, greatest)
            dfs(root.right, greatest)

        dfs(root, greatest)
        return count
            


