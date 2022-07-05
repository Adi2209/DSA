/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node * dummy = new Node(0);
        Node * tempdum = dummy;
        dummy->next = head;
        
        Node * temp = head;
        while(temp){
            Node * newnode = new Node(temp->val);
            newnode->next = temp->next;
            temp->next = newnode;
            temp = temp->next->next;
        }
        
        temp = head;
        while(temp){
            // cout<<temp->next->val<<endl;
            temp->next->random = (temp->random != NULL? temp->random->next : temp->random);
            temp = temp->next->next;
        }
        
        temp = head;
		//here we are making the original list back and joining the new nodes to the dummy node chain
        while(temp){
            tempdum->next = temp->next;
            tempdum = tempdum->next;
            temp->next = temp->next->next;
            temp = temp->next;
        }

        return dummy->next;
    }
};