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
    int kthSmallest(TreeNode* root, int k) {
        TreeNode* node = root;
        stack<TreeNode*> stack;

        while (node) {
            stack.push(node);
            node = node->left;
        }

        while (!stack.empty()) {
            if(--k == 0)
                return stack.top()->val;
            node = stack.top();
            stack.pop();

            if (node->right) {
                node = node->right;
                while (node) {
                    stack.push(node);
                    node = node->left;
                }
            }
        }
        return 0;
    }
};
