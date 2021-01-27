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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.empty())
            return nullptr;

        int val = preorder[0];
        vector<int>::iterator in_iter;
        vector<int>::iterator pre_iter;

        in_iter = find(inorder.begin(), inorder.end(), val);
        vector<int> in_left(inorder.begin(), in_iter);
        vector<int> in_right(in_iter + 1, inorder.end());

        vector<int> pre_left(preorder.begin()+1, preorder.begin()+1+ in_left.size());
        vector<int> pre_right(preorder.begin()+1+in_left.size(), preorder.end());

        return new TreeNode(val,
                      buildTree(pre_left, in_left),
                      buildTree(pre_right, in_right)
                   );
    }
};
