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
    ListNode* middleNode(ListNode* head) {
        
        ListNode* fast=head->next;
        ListNode* slow=head;
        
         if(head==NULL ||head->next==NULL){
            return head;
        }
        
        while(fast){
            fast=fast->next;
            if(fast) fast=fast->next;
            
            slow=slow->next;
            
        }
        return slow;
    }
};