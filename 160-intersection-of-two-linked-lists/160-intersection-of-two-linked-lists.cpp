/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_map<int, ListNode*> mpA;
        unordered_map<int, ListNode*> mpB;

        while(headA && headB) {
            if(mpB.find(headA->val) != mpB.end() && mpB[headA->val] == headA)
                return headA;
            mpA[headA->val] = headA;
            headA = headA->next;
            if(mpA.find(headB->val) != mpA.end() && mpA[headB->val] == headB)
                return headB;
            mpB[headB->val] = headB;
            headB = headB->next;
        }
        while(headA) {
            if(mpB.find(headA->val) != mpB.end() && mpB[headA->val] == headA)
                return headA;
            mpA[headA->val] = headA;
            headA = headA->next;
        }
        while(headB) {
            if(mpA.find(headB->val) != mpA.end() && mpA[headB->val] == headB)
                return headB;
            mpB[headB->val] = headB;
            headB = headB->next;
        }
        
        return nullptr;
    }
};