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
    int mini=INT_MAX;
    int prev=INT_MAX;
public: 
    //we will do the inorder traversal but int the dfs function itself
    int getMinimumDifference(TreeNode* root) {
        if(!root) return 0;
        //L N R
        getMinimumDifference(root->left);
        mini = min(mini, abs(root->val - prev));
        prev = root->val;
        getMinimumDifference(root->right);
        
        return mini;
    }
};