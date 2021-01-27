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
    void find_leaves(TreeNode* node, vector<int>& list) {
        if (!node)
            return;
        if (!node->left && !node->right)
            list.push_back(node->val);
        find_leaves(node->left, list);
        find_leaves(node->right, list);
    }

    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> left_leaves;
        vector<int> right_leaves;

        find_leaves(root1, left_leaves);
        find_leaves(root2, right_leaves);

        return left_leaves == right_leaves;
    }
};
