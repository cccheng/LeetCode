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
    TreeNode** find_parent(TreeNode* root, int key) {
        if (!root)
            return nullptr;
        if (root->left && root->left->val == key)
            return &root->left;
        if (root->right && root->right->val == key)
            return &root->right;
        if (key < root->val)
            return find_parent(root->left, key);
        else
            return find_parent(root->right, key);
    }

    TreeNode* find_node(TreeNode* node, int key) {
        if (!node)
            return nullptr;
        if (node->val == key)
            return node;
        if (key < node->val)
            return find_node(node->left, key);
        else
            return find_node(node->right, key);
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        bool update_parent = true;

        if (!root)
            return nullptr;
        if (root->val == key) {
            update_parent = false;
            if (!root->left && !root->right)
                return nullptr;
        }

        TreeNode* target = find_node(root, key);
        if (!target) return root;
        if (target->left) {
            TreeNode* right_most = target->left;
            while (right_most->right) right_most = right_most->right;
            right_most->right = target->right;
            if (update_parent)
                *find_parent(root, key) = target->left;
            else
                return target->left;
        } else {
            if (update_parent)
                *find_parent(root, key) = target->right;
            else
                return target->right;
        }

        return root;
    }
};
