class flight{
    public:
    int stops,node,dist;
    flight(int stops,int node,int dist){
        this->stops=stops;
        this->node=node;
        this->dist=dist;
    }
    
};
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);
        
        for(auto it:flights){
            adj[it[0]].push_back({it[1],it[2]});
        }
        queue<flight> que;
        que.push({0,src,0});
        vector<int> dist(n,1e9);
        dist[src]=0;
        
        while(!que.empty()){
            int stops=que.front().stops;
            int node=que.front().node;
            int cost=que.front().dist;
            que.pop();
            if(stops>k) continue;
            for(auto it:adj[node]){
                int adjNode=it.first;
                int edgeDist=it.second;
                int newCost=cost + edgeDist;
                if(newCost <dist[adjNode] && stops<=k){
                    dist[adjNode]=newCost;
                    que.push({stops+1,adjNode,newCost});
                }
            }
        }
        
        if(dist[dst]==1e9) return -1;
        return dist[dst];
        
    }
};