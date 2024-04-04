class Solution {
private:
    int solve(int n){
        // base case
        vector<int> dp(n+1);
        dp[0] =1;
        dp[1]=1;
        for(int ind=2;ind<=n;ind++){
            dp[ind]=dp[ind-1]+dp[ind-2];
        }
        return dp[n];
    }
public:
    int climbStairs(int n) {
        return solve(n);
    }
};