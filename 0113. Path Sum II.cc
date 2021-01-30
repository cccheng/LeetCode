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
    void helper(TreeNode* node, int target, vector<int> &path, vector<vector<int>> &result) {
        path.push_back(node->val);
        if (!node->left && !node->right) {
            if (target == node->val)
                result.push_back(path);
        } else {
            if (node->left)
                helper(node->left, target - node->val, path, result);
            if (node->right)
                helper(node->right, target - node->val, path, result);
        }
        path.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if (!root)
            return {};

        vector<int> path;
        vector<vector<int>> result;
        helper(root, targetSum, path, result);

        return result;
    }
};
