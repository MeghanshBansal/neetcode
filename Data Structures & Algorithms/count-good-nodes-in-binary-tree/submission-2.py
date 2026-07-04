# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def goodNodes(self, root: TreeNode) -> int:
        ans = []
        if not root: return ans
        stack = [(root, root.val)]
        while len(stack):
            ele = stack.pop()
            node = ele[0]
            max_value = ele[1]

            if max_value <= node.val:
                ans.append(node.val)
            if node.left: 
                stack.append((node.left, max(max_value, node.left.val)))
            if node.right:
                stack.append((node.right, max(max_value, node.right.val)))
            
        return len(ans)
