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
     vector<int> preorder(TreeNode* root,vector<int> &ans){
         
         //base case
         if(root!=NULL){
        
         
         ans.push_back(root->val);
         
         if(root->left){
             preorder(root->left,ans);
         }
          if(root->right){
             preorder(root->right,ans);
         }
    }
         return ans;
         
         
     }
    
public:
    vector<int> preorderTraversal(TreeNode* root) {
        
        vector<int> ans;
        
         preorder(root,ans);
        return ans;
        
        
    }
};