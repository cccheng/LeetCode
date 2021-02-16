/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_set<ListNode*> hash;

        if (!headA || !headB)
            return nullptr;

        for (auto n = headA; n; n = n->next)
            hash.insert(n);

        for (auto n = headB; n; n = n->next) {
            if (hash.count(n))
                return n;
        }

        return nullptr;
    }
};
