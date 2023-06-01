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
        if(!headA) return headB;
        if(!headB) return headA;
        ListNode* tempA=headA, * tempB=headB;
        while(tempA!=tempB){
            if(!tempA) tempA=headB;
            else tempA=tempA->next;
            if(!tempB) tempB=headA;
            else tempB=tempB->next;
        }
        return tempA;
    }
};