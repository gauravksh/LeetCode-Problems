class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        ListNode* ans = head;
        
        ListNode* ptr = head->next;
        int cur_sum = 0;
        
        while (ptr) {
            while (ptr->val != 0) {
                cur_sum += ptr->val;
                ptr = ptr->next;
            }
            ans->val = cur_sum;
            cur_sum = 0;
            if (ptr->next == nullptr) {
                ans->next = nullptr;
                break;
            }
            ans->next = ptr;
            ans = ans->next;
            ptr = ptr->next;
        }
        
        return head;
    }
};