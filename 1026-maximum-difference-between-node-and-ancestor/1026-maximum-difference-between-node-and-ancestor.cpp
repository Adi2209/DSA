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
public:
     
    
    void getMax(TreeNode *root, int mx, int mi,int& diff){
        
        if(!root) return;
        
        // track minimum and maximum while going through a sequence or path
        mx = max(mx, root->val);
        mi = min(mi, root->val);
        
        diff = max(diff, mx - mi); // store maximum difference
        
        getMax(root->left,mx,mi,diff);
        getMax(root->right,mx,mi,diff);
    }
    
    int maxAncestorDiff(TreeNode* root) {
        
        if(!root) return 0;
        int diff = INT_MIN; // we want max difference
        int mx = INT_MIN, mi = INT_MAX;

        getMax(root,mx,mi,diff);
        
        return diff;
    }
};