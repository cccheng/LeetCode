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
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        if (original == target) {
            return cloned;
        }
        TreeNode *found = nullptr;
        
        if (original->left) {
            found = getTargetCopy(original->left, cloned->left, target);
            if (found)
                return found;
        }
        if (original->right) {
            found = getTargetCopy(original->right, cloned->right, target);
            if (found)
                return found;
        }
        return nullptr;
    }
};
