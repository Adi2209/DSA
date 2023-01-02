class Solution {
private:
    void dfs(int node, int parent, vector<int>& vis, vector<int> adj[], vector<int>& insertTime,vector<int>& low,
            vector<vector<int>>& bridges,int &timer){
        vis[node]=1;
        insertTime[node]=low[node]=timer;
        timer++;
        
        for(auto it:adj[node]){
            if(it==parent) continue;
            if(!vis[it]){
                dfs(it,node,vis,adj,insertTime,low,bridges,timer);
                low[node]=min(low[node],low[it]);
                if(low[it] > insertTime[node]){
                    bridges.push_back({it,node});
                }
            }
            else{
                low[node]=min(low[node],low[it]);
            }
        }
        
    }
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<int> adj[n];
        for(auto it:connections){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        
        vector<int> vis(n,0);
        vector<int> low(n);
        vector<int> insertTime(n);
        
        vector<vector<int>> bridges;
        int timer=1;
        for(int ind=0;ind<n;ind++){
            if(!vis[ind]){
                dfs(ind,-1,vis,adj,insertTime,low,bridges,timer);
            }
        }
        
        return bridges;
    }
};