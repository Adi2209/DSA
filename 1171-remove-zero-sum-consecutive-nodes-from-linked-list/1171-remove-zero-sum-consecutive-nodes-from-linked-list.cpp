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
private: 
    void storeSum(unordered_map<int,ListNode*>& mp,ListNode* head){
        //storing the cumulative sum till each node with the node
        ListNode* curr=head;
        int sum=0;
        while(curr){
            sum+=curr->val;
            mp[sum]=curr;
            curr=curr->next;
        }
    }
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        unordered_map<int,ListNode*> mp;
        ListNode* dummy=new ListNode(0);
        mp[0]=dummy;
        dummy->next=head;
        storeSum(mp,head);
        ListNode*curr=dummy;
        int sum=0;
        while(curr){
            sum+=curr->val;
            ListNode* tempNode=mp[sum];
            if(tempNode!=curr){
                curr->next=tempNode->next;
            }
            curr=curr->next;
        }
        return dummy->next;
    }
};