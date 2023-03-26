class Solution {
public:
    vector<vector<int>> graph;
    vector<int> visited;
    int ans = -1;

    void dfs(int node, int d, unordered_map<int, int>& mp){        
        visited[node] = 1;
        mp[node] = d;

        for(int child: graph[node]){
            if(visited[child] == 0){
                dfs(child, d+1, mp);
            }else if(mp.count(child)){
                // a -> b -> c -> d and if cycle if from d -> b, we reduce the distance of a
                ans = max(ans, d - mp[child] + 1);
            }
        }
    }

    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        graph.resize(n);
        visited.resize(n, 0);

        //build graph
        for(int i=0; i<n; i++){
            if(edges[i] != -1) graph[i].push_back(edges[i]);
        }

        for(int i=0; i<n; i++){
            unordered_map<int, int> mp; //keeps track of distance
            dfs(i, 0, mp);
        }

        return ans;
    }
};