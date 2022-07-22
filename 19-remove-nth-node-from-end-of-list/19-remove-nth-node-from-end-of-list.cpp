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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head || !head->next) return nullptr;
        ListNode* fast = head;
        ListNode* slow = head;
        // n = n-1;
        while(n--) {
            fast = fast->next;
        }
        ListNode* pre = NULL;
        while(fast) {
            pre = slow;
            slow = slow->next;
            fast = fast->next;
        }
        if(!pre) return head->next;
        pre->next = slow->next;
        
        return head;
    }
};