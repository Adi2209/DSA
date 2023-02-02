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
    vector<TreeNode*> solveMemo(int n,unordered_map<int,vector<TreeNode*>>& mp){
        //base case
        vector<TreeNode*> allCombinations;
        if (n<1 || n%2==0){
            // if n is less than 1 or a multiple of 2: cannot have a FULL binary tree
            return allCombinations;
        }
        if(n==1){
            allCombinations.push_back(new TreeNode(0));
            mp[1]=allCombinations;
            return allCombinations;
        }        
        if(mp.find(n)!=mp.end()) return mp[n];
        for(int i=1;i<n;i+=2){
            //recursion will see and get the ans for each 'n'
            vector<TreeNode*> leftSubTree=solveMemo(i,mp);
            vector<TreeNode*> rightSubTree=solveMemo(n-i-1,mp);
            
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
        return mp[n]=allCombinations;
    }
public:
    vector<TreeNode*> allPossibleFBT(int n) {
        unordered_map<int,vector<TreeNode*>> mp;
        // n --> vec
        return solveMemo(n,mp);
    }
};