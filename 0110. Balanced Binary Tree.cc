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
    int length(TreeNode* root) {
        if (!root)
            return 0;
        return 1 + max(length(root->left), length(root->right));
    }
    bool isBalanced(TreeNode* root) {
        if (!root)
            return true;
        if (abs(length(root->right) - length(root->left)) > 1)
            return false;
        return isBalanced(root->right) && isBalanced(root->left);
    }
};
