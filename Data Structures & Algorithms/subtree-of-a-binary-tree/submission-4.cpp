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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (root == nullptr && subRoot == nullptr) return true; 
        if (root != nullptr) 
        {
            if (root->val == subRoot->val) 
            {
                bool res = this->checkSameTree(root, subRoot);
                if (res) return true;
            }

            bool left = this->isSubtree(root->left, subRoot);
            if (left) return true; 

            bool right = this->isSubtree(root->right, subRoot);
            if (right) return true; 
        }
        return false; 
    }

    bool checkSameTree(TreeNode *p, TreeNode *q) {
        if (p == nullptr && q == nullptr) return true; 
        if ((p == nullptr && q != nullptr) || (p != nullptr && q == nullptr)) return false; 
        if (p->val != q->val) return false; 

        return this->checkSameTree(p->left, q->left) && this->checkSameTree(p->right, q->right);
    }
};
