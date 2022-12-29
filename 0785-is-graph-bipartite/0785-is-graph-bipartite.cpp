class Solution {
private:
    bool dfs(int node,int col,vector<int>& color,vector<vector<int>>& graph){
        
        color[node]=col;
        
        for(auto it:graph[node]){
            if(color[it]==-1){
                bool dfsCall=dfs(it,!col,color,graph);
                if(!dfsCall) return false;
            }
            
            else if(color[it]==color[node]) return false;
                                   
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
         vector<int> color(n,-1);
        for(int i=0;i<n;i++){
            if(color[i]==-1){
                if(!dfs(i,0,color,graph)) return false;//starting with color 0
            }
        }
        return true;
    }
};