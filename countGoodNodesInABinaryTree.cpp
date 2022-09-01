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
    // int ans=0;
    void solve(TreeNode* root,int maxi,int& ans){
        //base case
        if(!root) return;
        if(root->val>=maxi) ans++;
        solve(root->left,max(root->val,maxi),ans);
        solve(root->right,max(root->val,maxi),ans);
        
    }
public:
    int goodNodes(TreeNode* root) {
        int ans=0;
        solve(root,root->val,ans);
        return ans;
    }
};
