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
    void inorder(TreeNode* root, vector<int> &inorderValue){
        
        if(!root)
            return;
        //LNR
        
        inorder(root->left,inorderValue);
        inorderValue.push_back(root->val);
        inorder(root->right,inorderValue);
    }
public:
    bool findTarget(TreeNode* root, int k) {
        
        vector<int> inorderValue;
        inorder(root,inorderValue);
        
        int l=0;
        int r=inorderValue.size()-1;
        
        while(l<r){
            if(inorderValue[l]+inorderValue[r]==k){
                return true;
            }
            else if(inorderValue[l]+inorderValue[r]>k){
                r--;
            }
            else
                l++;
        }
        
        return false;
        
    }
};
