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
        ListNode* pre=NULL;
        ListNode* next=NULL;
        
        while(head){
            next=head->next;
            head->next=pre;
            pre=head;
            head=next;
        }
        return pre;
    }
public:
    bool isPalindrome(ListNode* head) {
        
        if(!head || !head->next) return true;   
        ListNode* slow=head,*fast=head;
        
        while(fast->next && fast->next->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        slow->next=reverse(slow->next);
        slow=slow->next;
        
        while(slow){
            if(slow->val!=head->val) return false;
            head=head->next;
            slow=slow->next;
        }
        
        return true;
    }
};