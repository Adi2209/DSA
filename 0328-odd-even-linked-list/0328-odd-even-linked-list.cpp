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
    ListNode* oddEvenList(ListNode* head) {
        
        if(head==NULL || head->next==NULL) return head;
        
        ListNode* odd=head;
        ListNode* even=head->next;
        ListNode* firsteven=head->next;
        
        while(odd->next!=NULL && even->next !=NULL){
            odd->next=even->next; //saare odds ko joddo
            even->next=odd->next->next;// saare evens ko joddo
            odd=odd->next;
            even=even->next;
        }
        
        odd->next=firsteven;
        return head;
        
        
    }
};