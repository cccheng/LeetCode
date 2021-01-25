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
    int *previous = NULL;
    
    bool isValidBST(TreeNode* root) {
        if (root == NULL)
            return true;
        
        if (!isValidBST(root->left))
            return false;
        
        if (previous && root->val <= *previous)
            return false;
        
        previous = &root->val;
        
        if (!isValidBST(root->right))
            return false;
        
        return true;
    }
};
