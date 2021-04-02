/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
    void serialize(TreeNode *node, ostringstream& oss) {
        if (node) {
            oss << node->val << " ";
            serialize(node->left, oss);
            serialize(node->right, oss);
        } else {
            oss << "# ";
        }
    }

    TreeNode* deserialize(istringstream& iss) {
        string val;
        iss >> val;

        if (val == "#") {
            return nullptr;
        } else {
            TreeNode* node = new TreeNode(stol(val));
            node->left = deserialize(iss);
            node->right = deserialize(iss);
            return node;
        }
    }
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        ostringstream oss;
        serialize(root, oss);
        return oss.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream iss(data);
        return deserialize(iss);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
