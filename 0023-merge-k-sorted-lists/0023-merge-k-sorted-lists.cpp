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
    
    ListNode* mergesort(ListNode* a  , ListNode* b) {
        if(!a) 
            return b;
        if(!b)
            return a;
        ListNode* ans=NULL;
        if(a->val<=b->val)
        {
            ans=a;
            ans->next = mergesort(a->next,b);
        }
        else
        {
            ans=b;
            ans->next = mergesort(a,b->next);
        }
        return ans;
    }
    
    ListNode* mergeK(vector<ListNode*>& lists,int k) {
        while(k!=0) {
            int i = 0,j = k;
            while(i<j) {
                lists[i]=mergesort(lists[i],lists[j]);
                i++;
                j--;
                if(i>=j) 
                    k=j;
            }
        }
        return lists[0];
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==1)
            return lists[0];
        if(lists.size()==0) 
            return NULL;
        ListNode*newhead = mergeK(lists,lists.size()-1);
        return newhead;
    }
};