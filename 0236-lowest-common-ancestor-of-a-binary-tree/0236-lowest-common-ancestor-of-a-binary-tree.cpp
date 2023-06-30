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
        if(!root || root==p || root==q) return root;
        
        TreeNode* leftSubtree=lowestCommonAncestor(root->left,p,q);
        TreeNode* rightSubtree=lowestCommonAncestor(root->right,p,q);
        
        if(!leftSubtree) return rightSubtree;
        else if(!rightSubtree) return leftSubtree;
        else return root;
    }
};