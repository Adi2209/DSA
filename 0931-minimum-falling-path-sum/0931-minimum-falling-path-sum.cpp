class Solution {
private:
    int solve(int rows, int cols, vector<vector<int>>&matrix,vector<vector<int>>& dp){
        
        if(cols<0 || cols>=matrix.size()){
            return 1e9;
        }
        if(rows==0){
            return matrix[rows][cols];
        }
        if(dp[rows][cols]!=-1) return dp[rows][cols];
        int up = matrix[rows][cols] + solve(rows-1,cols,matrix,dp);
        int left = matrix[rows][cols] + solve(rows-1,cols-1,matrix,dp);
        int right = matrix[rows][cols] + solve(rows-1,cols+1,matrix,dp);
        
        return dp[rows][cols]=min(up, min(left,right));
    }
    
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int rows=matrix.size();
        int cols=matrix[0].size();
        vector<vector<int>> dp(rows+1,vector<int>(cols+1,-1));
        int result=1e9;
        for(int itr=0;itr<cols;itr++){
            int temp=solve(rows-1,itr,matrix,dp);
            result = min(result,temp);
        }
        
        return result;
    }
};