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
        if(!head || !head->next || k == 0) return head;
        int len = 0;
        ListNode* temp = head;
        while(temp) {
            len++;
            temp = temp->next;
        }
        k = k%len;
        // k = len - k;
        if(k==0) return head;
        ListNode* dummy = new ListNode();
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* pre = head;
        while(k--) fast = fast->next;
        while(fast->next) {
            slow = slow->next;
            // pre = fast;
            fast = fast->next;
        }
        if(slow->next) dummy->next = slow->next;
        else dummy->next = fast;
        fast->next = head;
        // cout << head->val;
        slow->next = NULL;
        
        return dummy->next;
    }
};