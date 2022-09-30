class Solution
{
    int rec(int r, int c, int& m, int& n, vector<vector<int>>& grid, vector<vector<int>>& dp)
    {
        // Base Cases
        if(r==m-1 && c==n-1)
            return grid[r][c];
        if(r >= m || c >= n)
            return 1000;  // Random big number
        if(dp[r][c] != -1)
            return dp[r][c];
        
        int down = grid[r][c] + rec(r+1,c,m,n,grid,dp);
        int right = grid[r][c] + rec(r,c+1,m,n,grid,dp);
        
        
        return dp[r][c] = min(down,right);
    }
public:
    int minPathSum(vector<vector<int>>& grid)
    {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        int ans = rec(0,0,m,n,grid,dp);
        return ans;
    }
};
