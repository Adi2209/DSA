/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    int maxDepth(Node* root) {
        if(!root) return NULL;
        int ans=1;
        for(int ind=0;ind<root->children.size();ind++){
            ans=max(ans,1+maxDepth(root->children[ind]));
        }
        return ans;
    }
};