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
    ListNode* oddEvenList(ListNode* head) {
        ListNode odd_dummy;
        ListNode* odd = &odd_dummy;
        ListNode even_dummy;
        ListNode* even;

        if (head) {
            odd->next = head;
            odd = odd->next;
        }
        if (odd->next) {
            even = odd->next;
            even_dummy.next = even;
        }

        while (odd && even) {
            if (odd->next == even) {
                odd->next = even->next;
                odd = odd->next;
            } else {
                even->next = odd->next;
                even = even->next;
            }
        }

        for (odd = &odd_dummy; odd->next; odd = odd->next)
            ;
        odd->next = even_dummy.next;

        return odd_dummy.next;
    }
};
