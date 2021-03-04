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

// v2
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
        int lenA = 0, lenB = 0;

        if (!headA || !headB)
            return nullptr;

        for (auto p = headA; p; p = p->next)
            lenA++;
        for (auto p = headB; p; p = p->next)
            lenB++;

        if (lenA > lenB) {
            for (; lenA > lenB; headA = headA->next, lenA--)
                ;
        } else {
            for (; lenB > lenA; headB = headB->next, lenB--)
                ;
        }

        while (headA && headB) {
            if (headA == headB)
                return headA;
            headA = headA->next;
            headB = headB->next;
        }

        return nullptr;
    }
};

// v3
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* a = headA;
        ListNode* b = headB;

        if (!a || !b)
            return nullptr;

        while (a && b) {
            if (a == b)
                return a;

            if (a->next)
                a = a->next;
            else {
                a = headB;
                headB = nullptr;
            }
            if (b->next)
                b = b->next;
            else {
                b = headA;
                headA = nullptr;
            }
        }

        return nullptr;
    }
};
