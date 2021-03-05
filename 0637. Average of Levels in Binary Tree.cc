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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> result;
        vector<int> count;
        
        function<void(TreeNode*,int)> dfs = [&](TreeNode* node, int level) -> void {
            if (!node)
                return;
            
            if (result.size() <= level) {
                result.push_back(node->val);
                count.push_back(1);
            } else {
                result[level] += node->val;
                count[level]++;
            }
            
            dfs(node->left, level+1);
            dfs(node->right, level+1);
        };
        
        dfs(root, 0);
        
        for (int i = 0; i < result.size(); ++i)
            result[i] = result[i] / count[i];
        
        return result;
    }
};
