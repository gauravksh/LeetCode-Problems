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
    ListNode* partition(ListNode* head, int x) {
        if(!head) return head;
        ListNode* temp = head;
        ListNode* dummy = new ListNode();
        ListNode* ans = dummy;
        // dummy->next = head;
        while(temp) {
            if(temp->val < x) {
                dummy->next = temp;
                dummy = dummy->next;
                temp = temp->next;
            }
            else {
                ListNode* cur = temp;
                ListNode* pre;
                while(cur && cur->val >= x) {
                    pre = cur;  
                    cur = cur->next;
                }
                if(!cur) {
                    dummy->next = temp;
                    break;
                }
                pre->next = cur->next;
                cur->next = temp;
                // cout << cur->next->val;
                dummy->next = cur;
                dummy = dummy->next;
            }   
        }
        return ans->next;
    }
};