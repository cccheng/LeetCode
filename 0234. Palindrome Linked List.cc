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
    ListNode* reverse(ListNode* node) {
        if (!node || !node->next)
            return node;

        ListNode* newhead = reverse(node->next);
        node->next->next = node;
        node->next = nullptr;
        return newhead;
    }
    bool isPalindrome(ListNode* head) {
        ListNode *slow = head, *fast = head;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        if (fast) slow = slow->next;
        ListNode* rlist = reverse(slow);

        for (auto a = rlist, b = head; a; a = a->next, b = b->next)
            if (a->val != b->val)
                return false;

        return true;
    }
};
