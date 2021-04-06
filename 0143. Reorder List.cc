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
    ListNode* reverse(ListNode* node) {
        if (!node || !node->next)
            return node;

        ListNode* r = reverse(node->next);
        node->next->next = node;
        node->next = nullptr;
        return r;
    }

public:
    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }

        ListNode* head2 = reverse(slow);
        while (head2 && head2->next) {
            ListNode* head_next = head->next;
            ListNode* head2_next = head2->next;

            head->next = head2;
            head2->next = head_next;

            head = head_next;
            head2 = head2_next;
        }
    }
};
