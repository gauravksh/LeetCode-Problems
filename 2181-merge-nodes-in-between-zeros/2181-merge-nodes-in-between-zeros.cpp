class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        ListNode* res = new ListNode(0);
        ListNode* ans = res;
        
        ListNode* ptr = head->next;
        int cur_sum = 0;
        while (ptr) {
            while (ptr->val != 0) {
                cur_sum += ptr->val;
                ptr = ptr->next;
            }
            res->next = new ListNode(cur_sum);
            res = res->next;
            cur_sum = 0;
            ptr = ptr->next;
        }
        
        return ans->next;
    }
};