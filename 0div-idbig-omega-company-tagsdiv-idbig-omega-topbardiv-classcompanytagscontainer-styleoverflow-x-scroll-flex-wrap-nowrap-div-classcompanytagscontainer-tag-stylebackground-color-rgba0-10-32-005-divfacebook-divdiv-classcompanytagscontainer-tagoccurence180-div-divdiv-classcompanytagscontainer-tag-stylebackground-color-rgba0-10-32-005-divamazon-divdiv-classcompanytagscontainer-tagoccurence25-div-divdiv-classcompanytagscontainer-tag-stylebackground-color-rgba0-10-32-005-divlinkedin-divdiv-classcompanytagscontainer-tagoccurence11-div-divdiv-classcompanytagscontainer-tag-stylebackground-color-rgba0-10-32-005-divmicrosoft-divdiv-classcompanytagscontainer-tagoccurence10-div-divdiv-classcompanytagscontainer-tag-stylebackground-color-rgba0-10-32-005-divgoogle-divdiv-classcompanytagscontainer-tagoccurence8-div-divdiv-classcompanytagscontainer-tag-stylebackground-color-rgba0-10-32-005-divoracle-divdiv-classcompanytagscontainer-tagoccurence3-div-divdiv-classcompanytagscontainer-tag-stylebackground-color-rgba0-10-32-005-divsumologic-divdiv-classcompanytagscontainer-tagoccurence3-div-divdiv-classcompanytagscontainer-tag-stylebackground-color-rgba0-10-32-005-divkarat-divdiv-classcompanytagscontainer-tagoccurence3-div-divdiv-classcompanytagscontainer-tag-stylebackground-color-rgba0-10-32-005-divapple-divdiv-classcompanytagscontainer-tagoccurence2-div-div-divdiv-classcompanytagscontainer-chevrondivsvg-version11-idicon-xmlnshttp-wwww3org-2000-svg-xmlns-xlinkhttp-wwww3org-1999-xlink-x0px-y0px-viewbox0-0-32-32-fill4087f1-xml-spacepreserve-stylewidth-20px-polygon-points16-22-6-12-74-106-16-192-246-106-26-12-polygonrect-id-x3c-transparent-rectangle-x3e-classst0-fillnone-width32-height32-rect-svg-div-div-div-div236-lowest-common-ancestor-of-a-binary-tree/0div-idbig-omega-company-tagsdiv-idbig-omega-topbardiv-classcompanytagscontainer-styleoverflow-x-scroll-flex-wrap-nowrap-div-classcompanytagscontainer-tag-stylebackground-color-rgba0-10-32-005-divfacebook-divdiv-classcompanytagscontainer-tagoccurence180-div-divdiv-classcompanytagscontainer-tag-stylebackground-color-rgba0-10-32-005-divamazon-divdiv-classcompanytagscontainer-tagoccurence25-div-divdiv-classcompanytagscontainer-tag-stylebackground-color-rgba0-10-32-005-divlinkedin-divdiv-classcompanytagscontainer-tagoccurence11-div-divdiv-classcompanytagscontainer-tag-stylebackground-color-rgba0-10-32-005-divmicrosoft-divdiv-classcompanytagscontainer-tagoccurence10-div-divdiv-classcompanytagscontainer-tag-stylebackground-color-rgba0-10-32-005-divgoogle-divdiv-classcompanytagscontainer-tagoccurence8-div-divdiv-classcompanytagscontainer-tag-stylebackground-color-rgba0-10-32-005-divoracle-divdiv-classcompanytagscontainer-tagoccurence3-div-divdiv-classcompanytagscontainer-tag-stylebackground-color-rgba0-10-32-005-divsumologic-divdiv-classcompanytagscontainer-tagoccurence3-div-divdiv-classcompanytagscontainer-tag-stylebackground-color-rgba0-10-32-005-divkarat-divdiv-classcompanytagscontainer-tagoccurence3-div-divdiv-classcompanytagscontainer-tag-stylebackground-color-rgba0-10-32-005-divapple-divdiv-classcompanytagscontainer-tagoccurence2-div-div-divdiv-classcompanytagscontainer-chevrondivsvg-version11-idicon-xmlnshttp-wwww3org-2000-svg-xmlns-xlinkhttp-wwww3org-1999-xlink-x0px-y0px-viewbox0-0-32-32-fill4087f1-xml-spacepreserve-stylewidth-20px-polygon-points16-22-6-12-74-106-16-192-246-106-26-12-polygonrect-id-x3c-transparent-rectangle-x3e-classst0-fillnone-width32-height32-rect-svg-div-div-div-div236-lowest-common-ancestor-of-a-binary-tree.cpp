/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return NULL;
        if(root == p || root == q) return root;
        
        TreeNode* leftSubTree = lowestCommonAncestor(root->left,p,q);
        TreeNode* rightSubTree = lowestCommonAncestor(root->right,p,q);
        
        if(leftSubTree == NULL) return rightSubTree;
        else if(rightSubTree == NULL) return leftSubTree;
        else return root;
    }
};