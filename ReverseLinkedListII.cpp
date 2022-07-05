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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        
        //reaaching till left
        
        if(!head) return NULL;
        ListNode* curr=head;
        ListNode* prev=NULL;
        
        while(left>1){
            prev=curr;
            curr=curr->next;
            left--;
            right--;
        }
        //reversing the list
        ListNode* con=prev,*tail=curr; //Two nodes to help the set the connections of the list at the end of sublist reversal
        ListNode* temp=curr;
        
        while(right>0){
            temp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
            right--;
        }
        
        //now  setting the connections
        
        if(con!=NULL){
            con->next=prev;
        }
        else{
            //To handle the case if left=0
            head=prev;
        }
        tail->next = curr; //Even if current node is NULL, the tail node is the last node of the new list which in turn points to null
        return head;
    }
};