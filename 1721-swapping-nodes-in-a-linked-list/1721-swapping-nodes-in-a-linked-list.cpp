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
    ListNode* swapNodes(ListNode* head, int k) {
        
        ListNode* start=head;
        ListNode* end=head;
        ListNode* store=NULL;
    
        while(--k){
            start=start->next;
        }
        store=start;
        
        while(start->next){
            start=start->next;
            end=end->next;
        }
        
        swap(store->val,end->val);
        
        return head;
        
    }
};