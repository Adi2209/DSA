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
    string solveDFS(TreeNode* root,vector<TreeNode*>& duplicates,unordered_map<string,int>& treeMap){
        
        if(!root) return "";
        
        string leftSubtree=solveDFS(root->left,duplicates,treeMap);
        string rightSubtree=solveDFS(root->right,duplicates,treeMap);
        
        string currSubtree="("+ leftSubtree+ to_string(root->val) + rightSubtree +")";
        //if not added before, then add in the map
        if(treeMap[currSubtree]!=-1) treeMap[currSubtree]++;
        
        if(treeMap.find(currSubtree)!=treeMap.end()){
            if(treeMap[currSubtree]>1){
                duplicates.push_back(root);
                //marking as -1 so we don't add again into the map 
                treeMap[currSubtree]=-1;
            }
        }
        return currSubtree;
    }
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode*> duplicates;
        unordered_map<string,int> treeMap;
        solveDFS(root,duplicates,treeMap);
        return duplicates;
    }
};