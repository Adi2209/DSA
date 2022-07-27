class Solution
{
public:
    void dfs(int node, vector<int> adj[], int n, vector<bool> &visited)
    {

        visited[node] = true;
        for (auto i : adj[node])
        {
            if (!visited[i])
            {
                dfs(i, adj, n, visited);
            }
        }
    }

    long long countPairs(int n, vector<vector<int>> &edges)
    {

        vector<int> adj[n];
        int cnt = 0;
        for (int i = 0; i < edges.size(); i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }

        long long ans = 0;
        vector<bool> visited(n, false);
        vector<bool> temp(n, 0);

        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                dfs(i, adj, n, visited);
            }
            else
            {
                i++;
            }

            int c1 = 0, c2 = 0;
            for (int j = 0; j < n; j++)
            {
                if (visited[j] == false)
                {
                    c1++;
                }
                if (visited[j] == true && temp[j] != 1)
                {
                    c2++;
                    temp[j] = 1;
                }
            }

            ans += (c1 * c2);
            cnt++;
        }

        return ans;
    }
};