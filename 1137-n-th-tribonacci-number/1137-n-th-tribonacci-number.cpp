class Solution {
private:
    int solveTribonacci(int n,vector<int>& dp){
        if(n==0) return 0;
        if(n==1 || n==2) return 1;
        if(dp[n]!=-1) return dp[n];
        return dp[n]=solveTribonacci(n-1,dp)+solveTribonacci(n-2,dp)+solveTribonacci(n-3,dp);
    }
public:
    int tribonacci(int n) {
        vector<int> dp(n+1,-1);
        return solveTribonacci(n,dp);
    }
};