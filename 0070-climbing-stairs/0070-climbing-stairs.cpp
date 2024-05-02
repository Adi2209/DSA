class Solution {
private:
    int solve(int n,vector<int>& dp){
        if(n ==0) return 1;
        if(n==1) return 1;
        
        if(dp[n]!=-1) return dp[n];
        int oneStep = solve(n-1,dp);
        int twoStep = solve(n-2,dp);
        return dp[n]=oneStep+twoStep;
    }
public:
    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        return solve(n,dp);
    }
};