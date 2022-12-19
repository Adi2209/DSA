class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        if(n==1) return true;
        vector<vector<int>> adjList(n);
        for(int i=0;i<edges.size();i++){
                int u=edges[i][0];
                int v=edges[i][1];
                
                adjList[u].push_back(v);
                adjList[v].push_back(u);
        }
        queue<int> q;
        q.push(source);
        vector<int> vis(n,0);
        
        while(!q.empty()){
            int frontNode=q.front();
            q.pop();
            vis[frontNode]=1;
            if(frontNode==destination) return true;
            for(auto idx:adjList[frontNode]){
                if(vis[idx]==0)
                    q.push(idx);
            }
        }
        return false;
    }
};