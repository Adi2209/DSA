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
    ListNode* removeElements(ListNode* head, int val) {
        
        ListNode*curr=head;
         while(head != NULL && head -> val == val)    
            head = head -> next;//3rd test case example ke liye ek time aisa aayega jismein head->next=null ho jaayega
    
        if(!head) return NULL;
        
        while(curr->next){
            if(curr->next->val==val){
                curr->next=curr->next->next;
            }
            else
                curr=curr->next;
        }
        return head;
    }
};