/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        queue<pair<int,Node*>> que;

        if (!root)
            return root;

        que.push({0, root});

        while (!que.empty()) {
            auto [len, n] = que.front();
            que.pop();

            if (n->left)
                que.push({len+1, n->left});
            if (n->right)
                que.push({len+1, n->right});

            if (!que.empty() && que.front().first == len)
                n->next = que.front().second;
        }

        return root;
    }
};
