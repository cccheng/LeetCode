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
    TreeNode* addOneRow(TreeNode* root, int v, int d, bool left = true) {
        if (d == 1) {
            TreeNode* node = new TreeNode(v);
            if (left)
                node->left = root;
            else
                node->right = root;
            return node;
        } else {
            if (!root)
                return root;
            root->left = addOneRow(root->left, v, d-1, true);
            root->right = addOneRow(root->right, v, d-1, false);
            return root;
        }
    }
};
