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
    ListNode* successor = nullptr;
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (!head || !head->next)
            return head;

        if (m > 1) {
            head->next = reverseBetween(head->next, m - 1, n - 1);
            return head;
        } else if (n == 1) {
            successor = head->next;
            return head;
        } else {
            ListNode* node = reverseBetween(head->next, 1, n - 1);
            head->next->next = head;
            head->next = successor;
            return node;
        }
    }
};
