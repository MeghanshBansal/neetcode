/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans; 
        if (root == nullptr) return ans; 
        queue<TreeNode*> q; 
        int s = 0;
        vector<int> v;
        q.push(root);

        while (!q.empty())
        {
            s = q.size();
            v.clear();
            for (int i = 0; i < s; i++) 
            {
                TreeNode *node = q.front();
                q.pop();

                v.push_back(node->val);

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }

            ans.push_back(v);
        }

        return ans; 
    }
};
