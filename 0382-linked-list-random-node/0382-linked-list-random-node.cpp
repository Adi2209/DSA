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
    //we just need to print a random value of a node
    vector<int> ans;
    Solution(ListNode* head) {
        while(head){
            ans.push_back(head->val);
            head=head->next;
        }
    }
    
    int getRandom() {
        int n=ans.size();
        int pos=rand()%n;
        return ans[pos];
        
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */