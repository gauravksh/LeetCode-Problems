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
    ListNode* mergeNodes(ListNode* head) {
        bool flag = true;
        if(!head) return head;
        ListNode* tmp = head;
        int sum = 0;
        ListNode* res = new ListNode(NULL);
        ListNode* d1 = res;
        while(tmp) {
            if(tmp->val == 0) {
                if(sum) {
                    ListNode* dummy = new ListNode(sum);
                    res->next = dummy;
                    res = res->next;
                    sum = 0;
                    tmp = tmp->next;
                }
                else tmp = tmp->next;
            }
            else {
                sum += tmp->val;
                tmp = tmp->next;
            }
        }
        return d1->next;
    }
};