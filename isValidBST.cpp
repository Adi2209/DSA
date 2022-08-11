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
    bool solve(TreeNode* root,long mini,long maxi){
        
        if(!root) return true;
        if(root->val <= mini  || root->val >= maxi) return false;
        
        bool left= solve(root->left,mini,root->val);
        bool right= solve(root->right,root->val,maxi);
        
        return left && right;
    }
public:
    bool isValidBST(TreeNode* root) {
        return solve(root,LONG_MIN,LONG_MAX);
    }
};
