class Solution {
public:
    // Correct Solution
    // We are just making an undirected graph, where we are giving (+ve) sign to outgoing
    // edges and pretending that there is also the same incoming edge (or in general the opposite edge)
    // and inserting it into the adj[] list as (-ve) elements.
    // This is done so that the DFS doesn't stop when there are no outgoing edges 
    // (+ve edges) from the current edge. (Because there might be more outgoing edges afterwards)
    // Without the above idea, the basic idea fails in this test case : [[1,2],[2,0]].
    
    // Link to not fully correct code is given below
    // https://leetcode.com/submissions/detail/603533278/
    // This approach gets 72/76 test cases correct, but is not logically correct.
    // The below implementation corrects that.
    void makeGraph(vector<vector<int>>& connections,vector<int> adj[]){
        for(int i=0; i<connections.size(); i++){
            adj[connections[i][0]].push_back(connections[i][1]);
            adj[connections[i][1]].push_back(-connections[i][0]);
        }
    }
    void dfs(vector<int> adj[],vector<bool>& visited,int src,int &ans){
        visited[src] = true;
        for(int &v : adj[src]){
            if(!visited[abs(v)]){
                if(v > 0)
                    ans++;
                dfs(adj,visited,abs(v),ans);
            }
        }
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<int> adj[n];
        vector<bool> visited(n,false);
        int ans = 0;
        makeGraph(connections,adj);
        
        dfs(adj,visited,0,ans);
        return ans;
    }
};
