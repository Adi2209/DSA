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
    int solve(TreeNode* root){
        if(!root) return 0;
        
        int leftHeight=solve(root->left);
        int rightHeight=solve(root->right);
        
        return 1+max(leftHeight,rightHeight);
            
    }
public:
    int maxDepth(TreeNode* root) {
        if(!root) return NULL;
        return solve(root);
    }
};