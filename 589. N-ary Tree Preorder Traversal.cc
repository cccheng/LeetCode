/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> preorder(Node* root) {
        vector<int> result;
        stack<Node*> stack;

        if (!root)
            return {};

        stack.push(root);
        while (!stack.empty()) {
            Node* node = stack.top();
            stack.pop();
            result.push_back(node->val);

            for (auto i = node->children.rbegin(); i != node->children.rend(); ++i)
                stack.push(*i);
        }

        return result;
    }
};
