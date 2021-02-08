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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    ListNode* find_middle(ListNode* node) {
        ListNode* slow = node;
        ListNode* fast = node;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    ListNode* cut_node(ListNode* head, ListNode* target) {
        if (!head || !target || head == target)
            return nullptr;

        ListNode* n = head;
        while (n->next && n->next != target)
            n = n->next;
        n->next = nullptr;

        return head;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        if (!head)
            return nullptr;

        ListNode* middle = find_middle(head);
        TreeNode* root = new TreeNode(middle->val);
        root->left = sortedListToBST(cut_node(head, middle));
        root->right = sortedListToBST(middle->next);

        return root;
    }
};
