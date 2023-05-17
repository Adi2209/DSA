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
        
        ListNode* slow=head;
        ListNode* fast=head;
        
        while(fast && fast->next){
            fast=fast->next->next;
            slow=slow->next;
        }
        //now reverse
        ListNode* prev=NULL;
        ListNode* nextNode=NULL;
        while(slow){
            nextNode=slow->next;
            slow->next=prev;
            prev=slow;
            slow=nextNode;
            
        }
        
        //for max pair sum
        int sum=0;
        
        while(prev!=NULL){
            sum=max(sum,prev->val+head->val);
            prev=prev->next;
            head=head->next;
        }
        
        return sum;
        
    }
};