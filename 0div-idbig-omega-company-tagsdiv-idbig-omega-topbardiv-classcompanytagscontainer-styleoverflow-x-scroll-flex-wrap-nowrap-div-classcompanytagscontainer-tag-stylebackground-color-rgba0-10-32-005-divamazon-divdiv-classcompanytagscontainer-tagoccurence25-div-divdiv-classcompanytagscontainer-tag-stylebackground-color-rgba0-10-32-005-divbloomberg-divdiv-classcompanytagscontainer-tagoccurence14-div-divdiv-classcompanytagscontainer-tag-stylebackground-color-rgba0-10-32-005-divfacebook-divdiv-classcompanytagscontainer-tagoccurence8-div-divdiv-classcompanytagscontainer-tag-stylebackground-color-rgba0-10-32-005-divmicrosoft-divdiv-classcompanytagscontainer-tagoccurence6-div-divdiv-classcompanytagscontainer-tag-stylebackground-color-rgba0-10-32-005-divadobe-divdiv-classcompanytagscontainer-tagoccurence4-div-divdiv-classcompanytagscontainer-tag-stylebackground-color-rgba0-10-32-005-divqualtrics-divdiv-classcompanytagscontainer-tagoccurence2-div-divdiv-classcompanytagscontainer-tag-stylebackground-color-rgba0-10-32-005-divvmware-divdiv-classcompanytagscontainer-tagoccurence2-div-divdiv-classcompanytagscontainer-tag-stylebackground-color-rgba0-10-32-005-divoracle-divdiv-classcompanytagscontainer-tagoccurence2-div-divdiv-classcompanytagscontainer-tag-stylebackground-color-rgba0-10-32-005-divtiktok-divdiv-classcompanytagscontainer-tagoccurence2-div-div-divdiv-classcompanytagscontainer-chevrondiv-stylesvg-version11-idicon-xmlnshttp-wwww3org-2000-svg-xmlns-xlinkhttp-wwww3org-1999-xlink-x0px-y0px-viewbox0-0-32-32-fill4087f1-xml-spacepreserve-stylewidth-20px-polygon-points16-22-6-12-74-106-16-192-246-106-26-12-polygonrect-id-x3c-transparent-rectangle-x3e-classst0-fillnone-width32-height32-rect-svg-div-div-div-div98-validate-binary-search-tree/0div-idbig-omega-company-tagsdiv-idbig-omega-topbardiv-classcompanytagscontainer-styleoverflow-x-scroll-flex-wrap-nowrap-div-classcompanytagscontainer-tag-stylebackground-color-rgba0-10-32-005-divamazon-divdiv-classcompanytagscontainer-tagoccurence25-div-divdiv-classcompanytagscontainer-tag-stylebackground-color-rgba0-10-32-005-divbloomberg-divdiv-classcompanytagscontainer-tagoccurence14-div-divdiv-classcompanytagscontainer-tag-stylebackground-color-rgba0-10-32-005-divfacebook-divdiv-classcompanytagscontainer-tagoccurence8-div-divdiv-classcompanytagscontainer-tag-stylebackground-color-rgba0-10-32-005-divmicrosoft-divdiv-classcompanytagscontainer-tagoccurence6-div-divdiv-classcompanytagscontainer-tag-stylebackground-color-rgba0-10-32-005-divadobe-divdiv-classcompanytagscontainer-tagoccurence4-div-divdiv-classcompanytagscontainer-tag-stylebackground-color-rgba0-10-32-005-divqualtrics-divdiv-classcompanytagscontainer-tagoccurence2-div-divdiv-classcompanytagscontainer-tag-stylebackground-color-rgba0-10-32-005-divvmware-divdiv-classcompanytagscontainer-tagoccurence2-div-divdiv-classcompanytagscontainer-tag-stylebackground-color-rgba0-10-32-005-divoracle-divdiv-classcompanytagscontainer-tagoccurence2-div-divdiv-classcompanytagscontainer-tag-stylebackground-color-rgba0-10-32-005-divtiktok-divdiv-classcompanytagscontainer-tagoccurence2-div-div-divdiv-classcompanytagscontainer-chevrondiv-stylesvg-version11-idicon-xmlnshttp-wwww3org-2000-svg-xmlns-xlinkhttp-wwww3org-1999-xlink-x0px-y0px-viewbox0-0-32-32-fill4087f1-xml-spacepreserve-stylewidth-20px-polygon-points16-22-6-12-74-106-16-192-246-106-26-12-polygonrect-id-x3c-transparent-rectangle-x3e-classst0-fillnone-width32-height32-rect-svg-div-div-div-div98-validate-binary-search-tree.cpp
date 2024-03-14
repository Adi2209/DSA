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
    bool validate(TreeNode* root,long long mini, long long maxi){
        if(root == NULL) return true;
        if(root->val >= maxi || root->val <= mini) return false;
        bool leftSubTree = validate(root->left,mini,root->val);
        bool rightSubTree = validate(root->right,root->val,maxi);
        
        return leftSubTree && rightSubTree;
    }
public:
    bool isValidBST(TreeNode* root) {
        return validate(root,LONG_MIN,LONG_MAX);
    }
};