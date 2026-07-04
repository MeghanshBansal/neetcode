# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def kthSmallest(self, root: Optional[TreeNode], k: int) -> int:
        flatten_tree = []
        self.inorder(root, flatten_tree)

        return flatten_tree[k-1]
        



    def inorder(self, node, ans):
        if node is None: 
            return 
        self.inorder(node.left, ans)
        ans.append(node.val)
        self.inorder(node.right, ans)