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
    void inorder(vector<int>& in,TreeNode* root){
        if(!root) return;
        //L N R;
        
        inorder(in,root->left);
        in.push_back(root->val);
        inorder(in,root->right);
        
    }
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> in;
        inorder(in,root);
        return in;
    }
};