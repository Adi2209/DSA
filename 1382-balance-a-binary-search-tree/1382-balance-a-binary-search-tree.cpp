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
    
    TreeNode* inorderToBST(int s,int e, vector<int> &inorderValue){
        
        if(s>e)
            return NULL;
        
        int mid=s+(e-s)/2;
        
        TreeNode* root=new TreeNode(inorderValue[mid]);
        root->left=inorderToBST(s,mid-1,inorderValue);
        root->right=inorderToBST(mid+1,e,inorderValue);
        
        return root;
    }
public:
    TreeNode* balanceBST(TreeNode* root) {
        
        vector<int> inorderValue;
        inorder(root,inorderValue);
        
        return inorderToBST(0,inorderValue.size()-1,inorderValue);
        
    }
};