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
    bool isValidBST(TreeNode* root)
    {
        if (root == nullptr) return true; 
        int min = INT_MIN;
        int max = INT_MAX;
        return this->checkValid(root->left, min, root->val) && this->checkValid(root->right, root->val, max);
    }

    bool checkValid(TreeNode *root, int min, int max) 
    {
        if (root == nullptr) return true;
        if (root->val >= max || root->val <= min) return false;
        return this->checkValid(root->left, min, root->val) && this->checkValid(root->right, root->val, max);
    }
};
