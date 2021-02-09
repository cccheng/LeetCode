/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        stack<Node*> stack;
        vector<bool> visited(100+1, false);
        vector<Node*> cloned(100+1, nullptr);

        if (!node)
            return nullptr;

        stack.push(node);
        visited[node->val] = true;
        cloned[node->val] = new Node(node->val);

        while (!stack.empty()) {
            Node* old = stack.top();
            stack.pop();

            for (auto n : old->neighbors) {
                if (!visited[n->val]) {
                    visited[n->val] = true;
                    stack.push(n);
                }

                if (!cloned[n->val])
                    cloned[n->val] = new Node(n->val);
                cloned[old->val]->neighbors.push_back(cloned[n->val]);
            }
        }

        return cloned[node->val];
    }
};
