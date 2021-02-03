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
    vector<int> postorderTraversal(TreeNode* root) {
        TreeNode* cur = root;
        stack<TreeNode*> stack;
        vector<int> result;

        while (cur || !stack.empty()) {
            if (cur) {
                if (cur->right) stack.push(cur->right);
                stack.push(cur);
                cur = cur->left;
            } else {
                cur = stack.top();
                stack.pop();

                if (!stack.empty() && stack.top() == cur->right) {
                    TreeNode* tmp = cur;
                    cur = stack.top();
                    stack.pop();
                    stack.push(tmp);
                } else {
                    result.push_back(cur->val);
                    cur = nullptr;
                }
            }
        }

        return result;
    }
};
