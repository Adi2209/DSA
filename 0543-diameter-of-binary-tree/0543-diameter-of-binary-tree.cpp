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
    int traverseDFS(TreeNode* root,int& diameter){
        if(!root) return 0;
        
        int leftHeight = traverseDFS(root->left,diameter);
        int rightHeight = traverseDFS(root->right,diameter);
        
        diameter = max(diameter,leftHeight+rightHeight);
        
        return 1 + max(leftHeight,rightHeight);
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        traverseDFS(root,diameter);
        return diameter;
    }
};