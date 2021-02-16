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
    int findMinList(vector<ListNode*>& lists) {
        int idx = -1;
        int min = numeric_limits<int>::max();

        for (auto i = 0; i < lists.size(); ++i) {
            if (lists[i] && lists[i]->val < min) {
                min = lists[i]->val;
                idx = i;
            }
        }

        return idx;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode dummy;
        ListNode* cur = &dummy;

        for (int i = findMinList(lists); i != -1; i = findMinList(lists)) {
            cur->next = lists[i];
            cur = cur->next;
            lists[i] = lists[i]->next;
        }

        return dummy.next;
    }
};
