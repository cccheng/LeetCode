/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        vector<int> vec;
        for (auto n = head; n; n = n->next)
            vec.push_back(n->val);
        swap(vec[k - 1], vec[vec.size() - k]);

        ListNode* new_head = new ListNode(vec[0]);
        ListNode* n = new_head;
        for (auto i = 1; i < vec.size(); ++i) {
            n->next = new ListNode(vec[i]);
            n = n->next;
        }
        return new_head;
    }
};
