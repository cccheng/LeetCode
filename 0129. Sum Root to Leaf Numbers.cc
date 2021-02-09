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
    int sumNumbers(TreeNode* root) {
        int sum = 0;
        
        function<void(TreeNode*,int)> dfs = [&](TreeNode* node, int accum) {
            if (!node)
                return;
            if (!node->left && !node->right)
                sum += accum + node->val;
            else {
                dfs(node->left, 10*(accum + node->val));
                dfs(node->right, 10*(accum + node->val));
            }
        };
        
        dfs(root, 0);
        
        return sum;
    }
};
