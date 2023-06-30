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
    int traverseDFS(TreeNode* root){
        if(!root) return 0;
        
        int leftHeight=traverseDFS(root->left);
        int rightHeight=traverseDFS(root->right);
        if(leftHeight==-1 || rightHeight==-1) return -1;
        if(abs(leftHeight-rightHeight)>1) return -1;
        
        return 1+max(leftHeight,rightHeight);
    }
public:
    bool isBalanced(TreeNode* root) {
        return traverseDFS(root)!=-1;
    }
};