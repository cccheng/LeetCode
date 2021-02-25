/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* LCA = nullptr;
        int lowest = numeric_limits<int>::max();
        int encounter = 0;

        function<void(TreeNode*,int)> inorder = [&](TreeNode* node, int level) -> void {
            if (!node)
                return;

            inorder(node->left, level+1);

            if (encounter >= 2)
                return;

            if (node == p || node == q)
                encounter++;

            if (encounter && level < lowest) {
                lowest = level;
                LCA = node;
            }

            inorder(node->right, level+1);
        };

        inorder(root, 0);

        return LCA;
    }
};
