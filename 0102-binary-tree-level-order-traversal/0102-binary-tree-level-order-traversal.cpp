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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root) return ans;
        queue<TreeNode*> treeQueue;
        treeQueue.push(root);
        
        while(!treeQueue.empty()){
            int size=treeQueue.size();
            vector<int> nodes;
            for(int ind=0;ind<size;ind++){
                TreeNode* frontNode=treeQueue.front();
                treeQueue.pop();
                nodes.push_back(frontNode->val);
                if(frontNode->left) treeQueue.push(frontNode->left);
                if(frontNode->right) treeQueue.push(frontNode->right);
            }
            ans.push_back(nodes);
        }
        return ans;
    }
};