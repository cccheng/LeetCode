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
    vector<vector<int>> levelOrder(Node* root) {
        queue<pair<Node*, int>> queue;
        vector<vector<int>> result;
        int cur_level = 1;

        if (root)
            queue.push(make_pair(root, cur_level));

        vector<int> siblings;
        while (!queue.empty()) {
            auto cur = queue.front();
            queue.pop();

            if (cur.second != cur_level) {
                result.push_back(siblings);
                siblings = vector<int>();
                cur_level++;
            }

            siblings.push_back(cur.first->val);
            for (auto c : cur.first->children)
                queue.push(make_pair(c, cur_level+1));
        }
        if (!siblings.empty())
            result.push_back(siblings);

        return result;
    }
};
