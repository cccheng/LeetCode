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
    int sum;
    void reverse_inorder(TreeNode* node) {
        if (!node) return;

        if (node->right)
            reverse_inorder(node->right);
        sum += node->val;
        node->val = sum;
        if (node->left)
            reverse_inorder(node->left);
    }
    TreeNode* bstToGst(TreeNode* root) {
        sum = 0;
        reverse_inorder(root);
        return root;
    }
};
