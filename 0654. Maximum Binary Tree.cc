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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        TreeNode* left = nullptr;
        TreeNode* right = nullptr;

        vector<int>::iterator max_iter =
            max_element(nums.begin(), nums.end());

        if (max_iter == nums.end())
            return nullptr;
        if (max_iter != nums.begin()) {
            vector<int> left_part(nums.begin(), max_iter);
            left = constructMaximumBinaryTree(left_part);
        }
        if (max_iter + 1 != nums.end()) {
            vector<int> right_part(max_iter + 1, nums.end());
            right = constructMaximumBinaryTree(right_part);
        }

        return new TreeNode(*max_iter, left, right);
    }
};
