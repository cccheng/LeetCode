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
    ListNode* succesor = nullptr;

    ListNode* reverseN(ListNode* node, int n) {
        if (!node || !node->next)
            return node;

        if (n == 1) {
            succesor = node->next;
            return node;
        }

        ListNode* head = reverseN(node->next, n - 1);
        node->next->next = node;
        node->next = succesor;
        return head;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* nextgroup = head;
        for (auto i = 0; i < k; i++) {
            if (nextgroup)
                nextgroup = nextgroup->next;
            else
                return head;
        }

        ListNode* new_head = reverseN(head, k);
        head->next = reverseKGroup(nextgroup, k);
        return new_head;
    }
};
