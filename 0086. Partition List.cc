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
    ListNode* partition(ListNode* head, int x) {
        if (!head || !head->next)
            return head;

        ListNode dummy;
        dummy.next = head;

        ListNode *fast = &dummy, *slow = &dummy, *tmp;
        while (fast && fast->next) {
            if (fast->next->val < x) {
                if (fast == slow) {
                    slow = slow->next;
                    fast = fast->next;
                } else {
                    tmp = slow->next;
                    slow->next = fast->next;
                    fast->next = fast->next->next;
                    slow->next->next = tmp;
                    slow = slow->next;
                    // fast should stay here, because the new fast->next isn't checked.
                }
            } else {
                fast = fast->next;
            }
        }

        return dummy.next;
    }
};
