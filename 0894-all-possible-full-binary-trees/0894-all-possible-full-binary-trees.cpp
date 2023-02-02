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
    vector<TreeNode*> solveRec(int n){
        //base case
        vector<TreeNode*> allCombinations;
        if (n<1 || n%2==0){
            // if n is less than 1 or a multiple of 2: cannot have a FULL binary tree
            return allCombinations;
        }
        if(n==1){
            allCombinations.push_back(new TreeNode(0));
            return allCombinations;
        }        
        
        for(int i=1;i<n;i+=2){
            //recursion will see and get the ans for each 'n'
            vector<TreeNode*> leftSubTree=solveRec(i);
            vector<TreeNode*> rightSubTree=solveRec(n-i-1);
            
            for(int j=0;j<leftSubTree.size();j++){
                for(int k=0;k<rightSubTree.size();k++){
                    // now making trees from all possible combinations of left and right subtrees
                    TreeNode* root=new TreeNode(0);
                    root->left=leftSubTree[j];
                    root->right=rightSubTree[k];
                    allCombinations.push_back(root);
                }
            }
        }
        return allCombinations;
    }
public:
    vector<TreeNode*> allPossibleFBT(int n) {
        return solveRec(n);
    }
};