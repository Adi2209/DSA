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
private:
    ListNode* reverseList(ListNode* head){
        // if(!head) return NULL;
        ListNode* curr=head,*prev=NULL,* nxt=NULL;
        
        while(curr){
            nxt=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nxt;            
        }
        return prev;
    }
public:
    bool isPalindrome(ListNode* head) {
        if(!head || !head->next) return true;
        ListNode* slow=head, *fast=head;
        while(fast->next && fast->next->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        // now the slow pointer is at the middle now we will reverse the list from slow->next;
        slow->next=reverseList(slow->next);
        //moving to start form slow->next
        slow=slow->next;
        ListNode* temp=head;
        while(slow){
            if(temp->val!=slow->val) return false;
            slow=slow->next;
            temp=temp->next;
        }
        return true;
    }
};