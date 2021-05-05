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
    map<TreeNode*,int> memo_leaf;
    map<TreeNode*,int> memo_path;
public:
    int max_leaf(TreeNode* root) {
        if (!root)
            return 0;
        if (memo_leaf.count(root))
            return memo_leaf[root];

        memo_leaf[root] = max(root->val, root->val + max(max_leaf(root->left), max_leaf(root->right)));
        return memo_leaf[root];
    }
    int max_path(TreeNode* root) {
        if (!root)
            return 0;
        if (memo_path.count(root))
            return memo_path[root];

        memo_path[root] = max({root->val, root->val + max_leaf(root->left) + max_leaf(root->right), root->val + max_leaf(root->left), root->val + max_leaf(root->right)});
        return memo_path[root];
    }
    int maxPathSum(TreeNode* root) {
        int mx = numeric_limits<int>::min();

        if (!root)
            return 0;

        queue<TreeNode*> que;
        que.push(root);

        while (!que.empty()) {
            TreeNode* node = que.front();
            que.pop();

            mx = max(mx, max_path(node));
            if (node->left)
                que.push(node->left);
            if (node->right)
                que.push(node->right);
        }

        return mx;
    }
};

// v2
class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int mx = numeric_limits<int>::min();

        function<int(TreeNode*)> helper = [&](TreeNode* node) -> int {
            if (!node)
                return 0;

            auto left = max(0, helper(node->left));
            auto right = max(0, helper(node->right));

            mx = max(mx, left + node->val + right);
            return max(left, right) + node->val;
        };

        helper(root);
        return mx;
    }
};
