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
    vector<string> result;

    string print_path(std::vector<int>& path) {
        string output;

        if (path.empty())
            return output;

        output += to_string(path[0]);
        for(int i = 1; i < path.size(); ++i)
            output += "->" + to_string(path[i]);

        return output;
    }

    void depth_search(TreeNode* node, vector<int>& stack) {
        if (!node)
            return;
        stack.push_back(node->val);
        if (!node->left && !node->right)
            result.push_back(print_path(stack));
        else {
            depth_search(node->left, stack);
            depth_search(node->right, stack);
        }
        stack.pop_back();
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<int> stack;
        depth_search(root, stack);
        return result;
    }
};
