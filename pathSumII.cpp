class Solution {
public:
    void getAllPaths(TreeNode *root,int targetSum,vector<int> temp,vector<vector<int>> &ans)
    {
        if(!root)
            return;
        if(!root->left and !root->right and targetSum == root->val)
        {
            temp.push_back(root->val);
            ans.push_back(temp);
            return;
        }
        temp.push_back(root->val);
        getAllPaths(root->left,targetSum-root->val,temp,ans);
        getAllPaths(root->right,targetSum-root->val,temp,ans);
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) 
    {
        vector<vector<int>> ans;
        getAllPaths(root,targetSum,{},ans);
        return ans;
    }
};
