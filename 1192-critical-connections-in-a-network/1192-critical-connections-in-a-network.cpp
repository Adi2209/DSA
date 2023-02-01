class Solution {
private:
    void traverseDFS(int node,int parent,vector<int> &vis,vector<int> adjList[],
                     vector<vector<int>>& bridges,vector<int>& insertTime,vector<int>& low,
                     int &timer){
        vis[node]=1;
        low[node]=insertTime[node]=timer;
        timer++;
        
        for(auto it:adjList[node]){
            if(it==parent) continue;
            if(!vis[it]){
                traverseDFS(it,node,vis,adjList,bridges,insertTime,low,timer);
                low[node]=min(low[it],low[node]);
                //checking if it's a bridge
                if(low[it]> insertTime[node]){
                    bridges.push_back({it,node});
                }
                
            }
            else{
                low[node]=min(low[it],low[node]);
            }
        }
    }
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        //step1 : make the adjlist
        vector<int> adjList[n];
        for(auto it:connections){
            adjList[it[0]].push_back(it[1]);
            adjList[it[1]].push_back(it[0]);
        }
        //now 3 arrays will be reqd.
        vector<int> insertTime(n);
        vector<int> low(n);
        vector<int> vis(n,0);
        int timer=1;
        vector<vector<int>> bridges;
        for(int ind=0;ind<n;ind++){
            if(!vis[ind]){
                traverseDFS(ind,-1,vis,adjList,bridges,insertTime,low,timer);
            }
        }
        return bridges;
    }
};