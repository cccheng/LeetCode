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
    bool isSame(TreeNode* a, TreeNode* b) {
        if (!a && !b)
            return true;
        if (!a || !b)
            return false;
        if (a->val != b->val)
            return false;
        return isSame(a->left, b->left) && isSame(a->right, b->right);
    }
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if (!s && !t)
            return true;
        if (!s || !t)
            return false;
        if (s->val == t->val) {
            if (isSame(s->left, t->left) && isSame(s->right, t->right))
                return true;
        }
        return isSubtree(s->left, t) || isSubtree(s->right, t);
    }
};
