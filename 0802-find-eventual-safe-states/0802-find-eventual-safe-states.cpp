class Solution {
private:
    bool dfsCheck(int node,vector<vector<int>>& graph,vector<int>& vis,
                  vector<int>& pathVis,vector<int>& check){
        vis[node]=1;
        pathVis[node]=1;
        for(auto it:graph[node]){
            if(!vis[it]){
                if(dfsCheck(it,graph,vis,pathVis,check)){
                    check[node]=0;
                    return true;
                } 
            }
            else if(pathVis[it]){
                check[node]=0;
                return true;
            }
        }
        check[node]=1;
        pathVis[node]=0;
        return false;
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        //any one who is part of the cycle can't be a safe node
        //any one leads to a a cycle
        int n=graph.size();
        vector<int> vis(n,0);
        vector<int> pathVis(n,0);
        vector<int> safeNodes;
        vector<int> check(n,0);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfsCheck(i,graph,vis,pathVis,check);
            }
        }
        
        for(int i=0;i<n;i++){
            if(check[i]==1) safeNodes.push_back(i);
        }
        return safeNodes;
    }
};