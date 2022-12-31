/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node *solve(Node *node,unordered_map<Node *,Node *>&dict){
        if(!node)
            return NULL;
        if(dict.find(node)==dict.end()){
            dict[node]=new Node(node->val);
            for(auto it:node->neighbors){
                dict[node]->neighbors.push_back(solve(it,dict));
            }
        }
        return dict[node];
    }
    Node* cloneGraph(Node* node){
        // dict is a unordered_map whose key is the actual node and value is the copied node
        unordered_map<Node *,Node *>dict;
        return solve(node,dict);
    }
};