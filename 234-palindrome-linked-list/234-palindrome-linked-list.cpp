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
    bool isPalindrome(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast->next && fast->next->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        
        slow = slow->next;
        stack<int> tmp;
        while(slow){
            tmp.push(slow->val);
            slow = slow->next;
        }
        
        fast = head;
        while(!tmp.empty()) {
            if(fast->val != tmp.top()) return false;
            tmp.pop();
            fast = fast->next;
        }
        
        return true;
    }
};