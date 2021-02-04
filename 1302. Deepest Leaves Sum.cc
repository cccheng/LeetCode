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
    int level_sum(TreeNode* node, int level) {
        if (!node) return 0;
        if (level == 1)
            return node->val;
        return level_sum(node->left, level - 1) + level_sum(node->right, level - 1);
    }

    int tree_depth(TreeNode* node) {
        if (!node) return 0;
        return 1 + max(tree_depth(node->left), tree_depth(node->right));
    }

    int deepestLeavesSum(TreeNode* root) {
        return level_sum(root, tree_depth(root));
    }
};
