/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        
        if(!head) return NULL;
        Node* tail=head;
        
        Node* next1=flatten(head->child);
        Node* next2=flatten(head->next);
        
        if(next1){
            tail->next=next1;
            while(tail->next){
                tail->next->prev=tail;
                tail->child=NULL;
                tail=tail->next;
            }
        }
        tail->next=next2;
        if(next2) next2->prev=tail;
        
        return head;
        
    }
};