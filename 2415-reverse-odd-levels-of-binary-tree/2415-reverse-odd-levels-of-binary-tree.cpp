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
    void reverseOdd(TreeNode* leftTree,TreeNode* rightTree, int level){
        if(!leftTree && !rightTree)
            return;
        if(level%2==1) swap(leftTree->val,rightTree->val);
        reverseOdd(leftTree->left,rightTree->right,level+1);
        reverseOdd(leftTree->right,rightTree->left,level+1);
    }
public:
    TreeNode* reverseOddLevels(TreeNode* root) {
        reverseOdd(root->left,root->right,1);
        return root;
    }
};