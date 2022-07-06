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
    ListNode* reverse(ListNode* head){
        
        ListNode* prev=NULL;
        ListNode* curr=head;
        ListNode* nxt=NULL;
        
        while(curr){
            nxt=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nxt;
        }
        
        return prev;
    }
public:
    void reorderList(ListNode* head) {
        
        if(!head) return;
        
        //finding the middle of the linked list 
        
        ListNode* slow=head,*fast=head;
        
        while(fast && fast->next){
            fast=fast->next->next;
            slow=slow->next;
            
        }
        //reversing the second half of the list 
        
        ListNode* second=reverse(slow->next);
        slow->next=NULL;
        ListNode* first=head;
        
        //merging the two lists 
        
        while(second){
            ListNode* temp1=first->next;
            ListNode* temp2=second->next;
            first->next=second;
            second->next=temp1;
            first=temp1;
            second=temp2;
        }
   
    }
};