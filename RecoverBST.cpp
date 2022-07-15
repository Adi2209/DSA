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
    
    void inorder(TreeNode* root,vector<int> &in){
        if(!root) return;
        //lnr
        inorder(root->left,in);
        in.push_back(root->val);
        inorder(root->right,in);
    }
    int index=0;
    void res(TreeNode* root,vector<int> in){
        if(!root) return;
        
        res(root->left,in);
        root->val=in[index++];
        res(root->right,in);
    }
    
public:
    void recoverTree(TreeNode* root) {
        //make inorder
        //sort the inorder
        //rearrange the values of the bst
        vector<int> in;
        inorder(root,in);
        sort(in.begin(),in.end());
        res(root,in);

        
    }
};