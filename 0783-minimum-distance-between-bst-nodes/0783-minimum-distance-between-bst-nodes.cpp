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
    void solve(TreeNode* root,vector<int>& inorder){
        if(!root) return;
        //lnr
        solve(root->left,inorder);
        inorder.push_back(root->val);
        solve(root->right,inorder);
    }
public:
    int minDiffInBST(TreeNode* root) {
        if(!root) return 0;
        vector<int> inorder;
        solve(root,inorder);
        int minDiff=1e9;
        for(int ind=1;ind<inorder.size();ind++){
            int currDiff=inorder[ind]-inorder[ind-1];
            minDiff=min(minDiff,currDiff);
        }
        return minDiff;
    }
};