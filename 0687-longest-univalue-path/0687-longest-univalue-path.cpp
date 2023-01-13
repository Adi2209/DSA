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
    int solveDFS(TreeNode* root,int val,int &maxLen){
        if(!root)
            return 0;
        
        int left = solveDFS(root->left, root->val,maxLen);
        int right = solveDFS(root->right, root->val,maxLen);
        maxLen = max(maxLen,left+right);
        
        if(val == root->val)
            return max(left,right) + 1;
        
        return 0;
    }
public:
    int longestUnivaluePath(TreeNode* root) {
        int maxLen=0;
        solveDFS(root,INT_MIN,maxLen);
        return maxLen;
    }
};