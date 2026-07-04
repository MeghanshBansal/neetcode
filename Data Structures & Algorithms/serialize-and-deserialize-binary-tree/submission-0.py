# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Codec:
    
    # Encodes a tree to a single string.
    def serialize(self, root: Optional[TreeNode]) -> str:
        ans = []
        def dfs(root):
            nonlocal ans
            if root is None: 
                ans.append("N")
                return 

            ans.append(str(root.val))
            dfs(root.left)
            dfs(root.right)
        
        dfs(root)
        return ','.join(ans)

        
    # Decodes your encoded data to tree.
    def deserialize(self, data: str) -> Optional[TreeNode]:
        i = 0
        tree = data.split(',')

        def dfs():
            nonlocal tree
            nonlocal i 
            if tree[i] == "N":
                i += 1
                return None 

            root = TreeNode(int(tree[i]))
            i+=1
            root.left = dfs()
            root.right = dfs()

            return root 
        
        root = dfs()
        return root