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
    long long sum=0,maxPro=0;
    void totalSum(TreeNode* root){
        if(root==NULL)
            return;        
        totalSum(root->left);
        totalSum(root->right);
        sum+=root->val;
    }
    long long max_Product(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        
        long long leftSum=max_Product(root->left);
        long long rightSum=max_Product(root->right);
        long long subtreeSum=leftSum+rightSum+root->val;
        maxPro=max(maxPro, (sum-subtreeSum)*subtreeSum);
        cout<<sum<<" "<<subtreeSum<<endl;
        
        return subtreeSum;
        
    }
public:
    int maxProduct(TreeNode* root) {
        
        totalSum(root);
        max_Product(root);
        
        return (int)(maxPro%1000000007);
        
    }
};