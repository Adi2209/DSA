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
    void traverseDFS(TreeNode* root,int& ans, int sum){
        if(!root) return;
        
        sum*=10;
        sum+=root->val;
        if(root->left == NULL && root->right == NULL){
            ans+=sum;
            return;
        }
        traverseDFS(root->left,ans,sum);
        traverseDFS(root->right,ans,sum);
    }
public:
    int sumNumbers(TreeNode* root) {
        int ans = 0;
        traverseDFS(root,ans,0);
        return ans;
    }
};