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
    int sum=0;
    
    void dfs(TreeNode* root,int l,int r){
        if(!root) return ;
        
        if(root->val>=l && root->val<=r) sum+=root->val;
        
        dfs(root->left,l,r);
        dfs(root->right,l,r);
        
    }
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        dfs(root,low,high);
        return sum;
        
    }
};