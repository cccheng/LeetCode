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
    vector<int> output;
    void inorder(TreeNode* node) {
        if(node == NULL)
            return;
        inorder(node->left);
        output.push_back(node->val);
        inorder(node->right);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        inorder(root);
        return output;
    }
};

// v2
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> stack;
        TreeNode* cur = root;

        while (cur) {
            stack.push(cur);
            cur = cur->left;
        }

        while (!stack.empty()) {
            cur = stack.top();
            result.push_back(cur->val);
            stack.pop();

            cur = cur->right;
            while (cur) {
                stack.push(cur);
                cur = cur->left;
            }
        }

        return result;
    }
};
