class Solution {
public:
    int n;
    vector<int> visited;

    void dfs(int idx,vector<vector<int>> &stones){
        visited[idx] = true;
        for(int i=0;i<n;i++){
            if(visited[i]) continue;
            if(stones[idx][0] == stones[i][0] || stones[idx][1] == stones[i][1]){
                dfs(i,stones);
            }
        }
        return;
    }
    int removeStones(vector<vector<int>>& stones) {
        n = stones.size();
        visited.resize(n,0);
        int val = 0;
        for(int i=0;i<n;i++){
            if(visited[i]) continue;
            val++;
            dfs(i,stones);
        }
        return n - val;
    }
};
