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
    int solve(TreeNode* root,int& diameter){
        if(!root) return 0;
        int leftHalf=solve(root->left,diameter);
        int rightHalf=solve(root->right,diameter);
        
        diameter=max(diameter,leftHalf+rightHalf);
        return 1+max(rightHalf,leftHalf);
        
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        int diameter=0;
        solve(root,diameter);
        return diameter;
    }
};