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
    ListNode* partition(ListNode* head, int x) {
        
         //so there is nothing mentioned related to the greater elements of the ll 
        //so we just need to bring all the smaller nodes to the front so we will make 
        // two seperate ll and join them
        
        ListNode* smaller=new ListNode;
        ListNode* larger=new ListNode;
        
        ListNode* smallHead=smaller,*largeHead=larger;
        
        while(head){
            if(head->val < x){
                smaller->next=head;
                smaller=smaller->next;
            }
            else{
                larger->next=head;
                larger=larger->next;
            }
            head=head->next;
        }
        //now just joining the two lists
        larger->next=NULL;
        smaller->next=largeHead->next;
        
        return smallHead->next;
        
    }
};