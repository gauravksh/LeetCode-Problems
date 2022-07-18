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
    int getDecimalValue(ListNode* head) {
        vector<int> num;
        num.push_back(head->val);
        while(head->next != nullptr) {
            head = head->next;
            num.push_back(head->val); 
        }
        // cout << num[2];
        int res = 0,j = 0;
        for(int i = num.size()-1; i >= 0; i--) {
            if(num[j++]&1) res += pow(2,i);
        }
        return res;
    }
};