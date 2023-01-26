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
    vector<TreeNode*> getUniqueTree(int start,int end){
        vector<TreeNode*> uniqueTrees;
        if(start>end){
            uniqueTrees.push_back(NULL);
            return uniqueTrees;
        }
        for(int ind=start;ind<=end;ind++){
            vector<TreeNode*> leftSubTree=getUniqueTree(start,ind-1);
            vector<TreeNode*> rightSubTree=getUniqueTree(ind+1,end);
            
            for(int j=0;j<leftSubTree.size();j++){
                for(int k=0;k<rightSubTree.size();k++){
                    TreeNode* root= new TreeNode(ind);
                    root->left=leftSubTree[j];
                    root->right=rightSubTree[k];
                    uniqueTrees.push_back(root);
                }
            }
        }
        return uniqueTrees;
    }
public:
    vector<TreeNode*> generateTrees(int n) {
        return getUniqueTree(1,n);
    }
};