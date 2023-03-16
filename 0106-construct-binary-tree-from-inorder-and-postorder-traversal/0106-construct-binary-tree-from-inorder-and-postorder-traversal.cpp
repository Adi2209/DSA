/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
         map<int, int> m;
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        
        int n=inorder.size(), p=n-1;
        //we're making a map so that T(c)=0(nlogn) and space also o(n);
        for(int i=0;i<n;i++) m[inorder[i]] = i;
        return makeTree(postorder, inorder, 0, n-1, p);
    }
    
        
    TreeNode* makeTree(vector<int> &post, vector<int> &in, int l, int r, int &idx){
        if(l>r||idx<0 ) return NULL;
        
        TreeNode *root = new TreeNode(post[idx--]);//maing the root node
        
        int i=m[root->val];//taking the position form the map
        //recursive calls
        
        root->right = makeTree(post, in, i+1, r, idx);
        root->left = makeTree(post, in, l, i-1, idx);
        
        
        return root;
    
        
    }
};