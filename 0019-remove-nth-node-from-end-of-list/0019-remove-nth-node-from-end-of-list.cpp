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
        if(!head) return head;
        ListNode* fast=head,*slow=head;
        //traversing fast to the nth node from start
        while(n--) fast=fast->next;
        // now we will traverse to the end of the list and then slow will point to the nodeToBeDeleted
        if(!fast) return head->next;//this means we have to remove the head;
        while(fast->next){
            fast=fast->next;
            slow=slow->next;
        }
        ListNode* nodeToDel=slow->next;
        slow->next=nodeToDel->next;
        nodeToDel=NULL;
        return head;
    }
};