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
    
    TreeNode* solve(vector<int> in,vector<int> pre, int& index,int inorderStart,int inorderEnd,int n,map<int,int> &m){
        //base Case
        if(index>=n || inorderStart > inorderEnd){
            return NULL;
        }
        
        // create a root Node
        int element = pre[index++];
        TreeNode* root = new TreeNode(element);
        
        //find index of element in inorder
        int pos = m[element];
        
        //recursive call
        root->left = solve(in,pre,index,inorderStart,pos-1,n,m);
        root->right = solve(in,pre,index,pos+1,inorderEnd,n,m);
        
        return root;
    }
    
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int index =0;
        map<int,int> m;
        int n = preorder.size();
        
        //create map of inorder index
        for(int i=0; i<n; i++){
            m[inorder[i]]=i;
        }
        
        TreeNode* ans = solve(inorder,preorder,index,0,n-1,n,m);
        
        return ans;
    }
};