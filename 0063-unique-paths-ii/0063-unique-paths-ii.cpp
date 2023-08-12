class Solution {
private:
    int solve(int i,int j,vector<vector<int>> obstacleGrid,vector<vector<int>>& dp){
        
        //base case
        if(i>=obstacleGrid.size() || j>=obstacleGrid[0].size() || obstacleGrid[i][j]==1) return 0;
        if(i==obstacleGrid.size()-1 && j==obstacleGrid[0].size()-1) return 1;
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        return dp[i][j]=solve(i+1,j,obstacleGrid,dp)+solve(i,j+1,obstacleGrid,dp);
    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return solve(0,0,obstacleGrid,dp);
    }
};