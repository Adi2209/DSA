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
    void buildGraph(TreeNode* root,vector<vector<int>>& adj){
        if(!root) return;
        
        if(root->left){
            adj[root->val].push_back(root->left->val);
            adj[root->left->val].push_back(root->val);
        }
        if(root->right){
            adj[root->val].push_back(root->right->val);
            adj[root->right->val].push_back(root->val);
        }
        buildGraph(root->left,adj);
        buildGraph(root->right,adj);
    }
    void bfs(int start,vector<vector<int>>& adj,vector<int>& vis,int &ans){
        queue<int> q;
        q.push(start);
        while(!q.empty()){
            int size=q.size();
            for(int ind=0;ind<size;ind++){
                int frontNode=q.front();
                q.pop();
                vis[frontNode]=1;
                for(auto it:adj[frontNode]){
                    if(!vis[it]){
                        q.push(it);
                    }
                }
            }
            ans++;
        }
    }
public:
    int amountOfTime(TreeNode* root, int start) {
        vector<vector<int>> adj(1e5+1);
        vector<int> vis(1e5+1);
        
        buildGraph(root,adj);
        int ans=0;
        bfs(start,adj,vis,ans);
        return ans-1;
    }
};