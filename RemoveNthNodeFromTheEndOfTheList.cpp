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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        //we will start the fast pointer from nth node from the start ...this way when we will iterate normally then slow will be just before the pointer to be deleted and fast will be at the tend of the linked list
        
        if(!head) return NULL;
        
        ListNode* fast=head,*slow=head;
        
        while(n--) fast=fast->next;
        if(!fast) return head->next;//this means we have to remove the head;
        while(fast->next){
            slow=slow->next;
            fast=fast->next;
        }
        ListNode*nodeToDelete=slow->next;
        nodeToDelete=NULL;//deleting the node .(but it is not mentioned in the question)
        slow->next=slow->next->next;
        
        return head;
        
        
    }
};