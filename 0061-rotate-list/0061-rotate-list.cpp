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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next) return head;
        int len=1;
        ListNode* curr=head;
        while(curr->next!=NULL){
            curr=curr->next;
            len++;
        }
        //joining curr with head as curr is at last node
        curr->next=head;
        k=k%len;
        k=len-k;
        while(k){
            curr=curr->next;
            k--;
        }
        head=curr->next;
        curr->next=NULL;
        return head;
    }
};