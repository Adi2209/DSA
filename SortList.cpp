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
    ListNode* midpoint(ListNode* head){

        ListNode *slow = head, *fast = head->next;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        
        return slow;
    }
    
    ListNode* mergeSortedLists(ListNode* left, ListNode* right){
        if(left == NULL) return right;
        if(right == NULL) return left;
        
        ListNode* temp;
        if(left->val <= right->val){
            temp = left;
            temp->next = mergeSortedLists(left->next, right);
        }
        else{
            temp = right;
            temp->next = mergeSortedLists(left, right->next);
        }
        
        return temp;
    }
    
    ListNode* sortList(ListNode* head) {
        if(head == NULL or head->next == NULL){
            return head;
        }
        
        ListNode* mid = midpoint(head);
        ListNode* left = head;
        ListNode* right = mid->next;
        
        mid->next = NULL;
        
        left = sortList(left);
        right = sortList(right);
        
        ListNode* temp = mergeSortedLists(left, right);
        return temp;
    }
};