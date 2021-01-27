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
    int sum_tree(TreeNode* node) {
        if (!node)
            return 0;
        return node->val + sum_tree(node->left) + sum_tree(node->right);
    }
    void abs_diff(TreeNode* node) {
        if (!node)
            return;
        if (!node->left && node->right)
            node->val = abs(sum_tree(node->right));
        if (node->left && !node->right)
            node->val = abs(sum_tree(node->left));
        node->val = abs(sum_tree(node->left) - sum_tree(node->right));
        abs_diff(node->left);
        abs_diff(node->right);
    }
    int findTilt(TreeNode* root) {
        abs_diff(root);
        return sum_tree(root);
    }
};
