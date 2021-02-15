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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        deque<TreeNode*> buf;

        if (!root)
            return result;

        buf.push_back(root);

        bool reverse = false;
        while (!buf.empty()) {
            vector<int> output;
            deque<TreeNode*> next;

            for (auto n : buf) {
                output.push_back(n->val);
                if (n->left)
                    next.push_back(n->left);
                if (n->right)
                    next.push_back(n->right);
            }

            if (reverse)
                std::reverse(output.begin(), output.end());
            result.push_back(output);

            reverse = !reverse;
            buf.swap(next);
        }

        return result;
    }
};
