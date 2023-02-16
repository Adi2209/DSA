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
    int solve(TreeNode* root, int sum){
        if(!root) return 0;
        
        sum=root->val+sum*10;
        if(root->left==NULL && root->right==NULL) return sum;
        int leftSum=0,rightSum=0;
        if(root->left) leftSum=solve(root->left,sum);
        if(root->right) rightSum=solve(root->right,sum);
        
        return leftSum+rightSum;
    }
public:
    int sumNumbers(TreeNode* root) {
        return solve(root,0);
    }
};