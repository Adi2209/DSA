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
    void solve(TreeNode* &root, unordered_map<int,int>& mp , vector<TreeNode*> &ans){
        //we will do a psotorder traversal because in post order traversal the left and right childs are traversed before the root
        if(!root) return;
        
        //dfs calls for post order traversal LRN
        solve(root->left,mp,ans);
        solve(root->right,mp,ans);
        
        if(mp.find(root->val)!= mp.end()){
            if(root->left) ans.push_back(root->left);
            if(root->right) ans.push_back(root->right);
            //marking root->NULL as we want to delete  
            root=NULL;
        }
        
    }
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        unordered_map<int,int> mp;
        for(auto it:to_delete) mp[it]++;
        vector<TreeNode*> ans;
        solve(root,mp,ans);
        if(root) ans.push_back(root);
        return ans;
    }
};