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
        
        ListNode* d1=headA;//dummy 1
        ListNode* d2=headB;//dummy 2
        
        while(d1!=d2){
            if(d1==NULL)
                d1=headB;
            else
                d1=d1->next;
            if(d2==NULL)
                d2=headA;
            else
                d2=d2->next;
        }
        return d1;
    }
};