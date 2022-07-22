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
    int pairSum(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast->next && fast->next->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode* mid = slow;
        ListNode* pre = NULL;
        ListNode* cur = slow->next;
        ListNode* tmp;
        while(cur) {
            tmp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = tmp;
        }
        mid->next = pre;
        mid = mid->next;
        int sum = 0, cur_sum = 0;
        while(mid) {
            cur_sum += head->val;
            cur_sum += mid->val;
            sum = max(sum,cur_sum);
            // cout << sum;
            head = head->next;
            mid = mid->next;
            cur_sum = 0;
        }
        
        return sum;
    }
};