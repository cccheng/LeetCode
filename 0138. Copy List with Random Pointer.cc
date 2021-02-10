/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head)
            return nullptr;
        
        Node* old_node = head;
        Node* new_node;
        map<Node*, Node*> mapping;
        
        while (old_node) {
            new_node = new Node(old_node->val);
            mapping[old_node] = new_node;
            old_node = old_node->next;
        }
        
        for (old_node = head; old_node; old_node = old_node->next) {
            new_node = mapping[old_node];
            new_node->next = mapping[old_node->next];
            new_node->random = mapping[old_node->random];
        }
        
        return mapping[head];
    }
};
