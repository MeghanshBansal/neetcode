# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def goodNodes(self, root: TreeNode) -> int:
        if root is None: 
            return []
        ans = []
        greatest_node = None
        self.dfs(root, greatest_node, ans)
        return len(ans)

    def dfs(self, root, greatest_in_path, ans):
        if root is None: 
            return 
        
        new_greatest = greatest_in_path
        if greatest_in_path is None or root.val >= greatest_in_path.val:
            ans.append(root.val)
            new_greatest = root

        self.dfs(root.left, new_greatest, ans)
        self.dfs(root.right, new_greatest, ans)
