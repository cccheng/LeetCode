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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        vector<TreeNode*> tmp;
        
        if (root == NULL)
            return result;
        tmp.push_back(root);
        
        while (!tmp.empty()) {
            vector<int> inner;
            vector<TreeNode*> new_tmp;
            
            for(int i = 0; i < tmp.size(); ++i) {
                inner.push_back(tmp[i]->val);
                if (tmp[i]->left)
                    new_tmp.push_back(tmp[i]->left);
                if (tmp[i]->right)
                    new_tmp.push_back(tmp[i]->right);
            }
            
            tmp = new_tmp;
            result.push_back(inner);
        }
        return result;
    }
};
