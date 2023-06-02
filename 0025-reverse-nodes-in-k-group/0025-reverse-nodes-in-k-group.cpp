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
        //first we will check if there are k nodes or not
        ListNode* temp=head;
        for(int ind=0;ind<k;ind++){
            if(temp==NULL) return head;
            temp=temp->next;
        }
        
        ListNode* curr=head, *prev=NULL, *nxt=NULL;
        for(int ind=0;ind<k;ind++){
            nxt=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nxt;
        }
        head->next=reverseKGroup(curr,k);
        return prev;
    }
};