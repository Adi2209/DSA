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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        
        stack<int>s1;
        stack<int>s2;
        
        while(l1){
            s1.push(l1->val);
            l1=l1->next;
        }
        while(l2){
            s2.push(l2->val);
            l2=l2->next;
        }
        //now extracting the elements from the stack
        int carry=0;
        ListNode* result=NULL;
        
        while(!s1.empty() || !s2.empty()){
            int a=0,b=0;
            if(!s1.empty()){
            a=s1.top();
            s1.pop();
            }
            if(!s2.empty()){
            b=s2.top();
            s2.pop();
            }
 
            int total=a+b+carry;
            
            ListNode* temp = new ListNode(total%10);
            carry=total/10;
            
            if(result==NULL){
                result=temp;
            }
            else{
                temp->next=result;
                result=temp;
            }  
        }
            
            if(carry!=0){
                ListNode* temp=new ListNode(carry);
                temp->next=result;
                result= temp;
            }
            
        
        return result;
    }
};