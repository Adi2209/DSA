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
    ListNode* reverseKGroup(ListNode* head, int k) {
        //base case
         ListNode* temp=head;
        for(int i=0;i<k;i++){
            if(temp==0)return head;
            temp=temp->next;
        }
        
        ListNode* prev=NULL;
        ListNode* curr=head;
        ListNode* next=NULL;
        int count=0;
        
        //ek case solve karte hue
        
        while(curr!=NULL && count<k){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
            count++;
        }
        
        //recursion kar lega baaki
        
        if(next!=NULL){
            head->next=reverseKGroup(next,k);
        }
        
        return prev;
    }
};