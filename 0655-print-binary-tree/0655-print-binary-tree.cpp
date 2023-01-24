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
    int getHeight(TreeNode* root){
        
        if(!root) return 0;
        
        int leftTree=getHeight(root->left);
        int rightTree=getHeight(root->right);
        return 1+max(leftTree,rightTree);
    }
    
    void getAns(vector<vector<string>>& ans,TreeNode* root,int row,int col,int height){
        if(!root) return;
        
        ans[row][col] = to_string(root->val);
        getAns(ans,root->left,row+1 ,col-(pow(2,height-row-1)),height);
        getAns(ans,root->right,row+1 ,col+(pow(2,height-row-1)),height);
    }
public:
    vector<vector<string>> printTree(TreeNode* root) {
        
        int height=getHeight(root);
        // as the question is not counting the root node in the height
        height--;
        int rows=height,cols=pow(2, height+1)-1;
        vector<vector<string>> ans(rows+1,vector<string>(cols,""));

        getAns(ans,root,0,(cols-1)/2,height);
        return ans;
    }
};