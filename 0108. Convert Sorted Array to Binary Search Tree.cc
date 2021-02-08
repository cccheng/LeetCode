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
    TreeNode* trans(vector<int>& nums, int begin, int end) {
        if (begin >= end)
            return nullptr;

        int middle = (begin + end) / 2;
        TreeNode* node = new TreeNode(nums[middle]);

        node->left = trans(nums, begin, middle);
        node->right = trans(nums, middle+1, end);
        return node;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if (nums.empty())
            return nullptr;

        return trans(nums, 0, nums.size());
    }
};
