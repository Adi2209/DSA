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
    bool isUnivalued(TreeNode* root,int prev){
        
        //base case
        if(!root) return true;
        if(root->val!=prev) return false;
            
        bool left=isUnivalued(root->left,prev);
        bool right=isUnivalued(root->right,prev);
        return left && right;
    }
public:
    bool isUnivalTree(TreeNode* root) {
        return isUnivalued(root,root->val);
    }
};