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
    TreeNode* right_most(TreeNode* node) {
        while (node->right)
            node = node->right;
        return node;
    }
    TreeNode* increasingBST(TreeNode* root) {
        if (!root)
            return nullptr;
        if (root->left) {
            TreeNode* new_root = increasingBST(root->left);
            right_most(root->left)->right = root;
            root->left = nullptr;
            root->right = increasingBST(root->right);
            return new_root;
        } else if (root->right) {
            root->right = increasingBST(root->right);
        }
        return root;
    }
};
