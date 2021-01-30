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
    vector<int> rightSideView(TreeNode* root) {
        int clevel = 0;
        vector<int> result;
        queue<pair<TreeNode*, int>> q;

        if (!root)
            return result;
        q.push(make_pair(root, 1));

        while (!q.empty()) {
            TreeNode* node = q.front().first;
            int level = q.front().second;

            if (level > clevel) {
                clevel = level;
                result.push_back(node->val);
            }

            q.pop();
            if (node->right) q.push(make_pair(node->right, clevel + 1));
            if (node->left) q.push(make_pair(node->left, clevel + 1));
        }

        return result;
    }
};
