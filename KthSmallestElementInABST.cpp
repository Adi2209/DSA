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
    int inorder(TreeNode* root,int &cnt){
        if(root==NULL) return -1;
        
        //lnr
        int left=inorder(root->left,cnt);
        if(left!=-1){
            return left;
        }
        cnt--;
        if(cnt==0) return root->val;
        return inorder(root->right,cnt);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        
        return inorder(root,k);
    }
};