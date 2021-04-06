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
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode* fast = head;
        ListNode* slow = head;

        if (!head)
            return head;

        int len = 0;
        for (ListNode* i = head; i; i = i->next)
            len++;

        if (len)
            k %= len;

        if (k == 0)
            return head;

        for (int i = 0; i < k; ++i)
            fast = fast->next;

        while (fast) {
            fast = fast->next;
            slow = slow->next;
        }

        ListNode *node = slow;
        while (node && node->next)
            node = node->next;

        if (k != 0) {
            node->next = head;
            while (node->next != slow)
                node = node->next;
            node->next = nullptr;
        }

        return slow;
    }
};
