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
    void solve(TreeNode* root,string &ans,string temp){
        if(!root) return;
        temp+=char(97+root->val);
        //leaf node encountered
        if(!root->left && !root->right){
            reverse(temp.begin(),temp.end());
            //first time
            if(ans=="") ans=temp;
            else{
                ans=min(ans,temp);
            }
        }
        solve(root->left,ans,temp);
        solve(root->right,ans,temp);
    }
public:
    string smallestFromLeaf(TreeNode* root) {
        string temp="";
        string ans="";
        if(!root) return ans;
        solve(root,ans,temp);
        return ans;
    }
};