class Solution {
    void dfs(int curr, string &colors, vector<int> adjList[], vector<bool> &visited, vector<bool> &currPath, vector<vector<int>> &count, int &ans) {
        if(currPath[curr] || ans == -1) {
            ans = -1;
            return;
        }
        if(visited[curr]) return;
        visited[curr] = true;
        currPath[curr] = true;
        for(int next: adjList[curr]) {
            dfs(next, colors, adjList, visited, currPath, count, ans);
            if(ans == -1) return;
            for(int i = 0; i < 26; i++) {
                count[curr][i] = max(count[curr][i], count[next][i]);
            }
        }
        count[curr][colors[curr] - 'a']++;
        ans = max(ans, count[curr][colors[curr] - 'a']);
        currPath[curr] = false;
    }
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.length();
        vector<int> adjList[n];
        for(vector<int> edge: edges) {
            adjList[edge[0]].push_back(edge[1]);
        }
        int ans = INT_MIN;
        vector<bool> visited(n), currPath(n);
        vector<vector<int>> count(n, vector<int>(26));
        for(int i = 0; i < n; i++) {
            dfs(i, colors, adjList, visited, currPath, count, ans);
        }
        return ans;
    }
};