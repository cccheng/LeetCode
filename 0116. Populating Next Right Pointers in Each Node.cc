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
    void connect_node(Node* a, Node* b) {
        if (!a)
            return;
        a->next = b;

        connect_node(a->left, a->right);
        connect_node(b->left, b->right);
        connect_node(a->right, b->left);
    }

    Node* connect(Node* root) {
        if (root)
            connect_node(root->left, root->right);

        return root;
    }
};
