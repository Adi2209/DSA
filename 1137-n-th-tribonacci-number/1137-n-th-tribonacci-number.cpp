class Solution {
private:
    int solveTab(int n){
        vector<int> dp(n+1,0);
        //base case
        dp[0]=0;
        dp[1]=dp[2]=1;
        if(n<=2) return dp[n];
        for(int ind=3;ind<=n;ind++){
            dp[ind]=dp[ind-1]+dp[ind-2]+dp[ind-3];
        }
        return dp[n];
    }
public:
    int tribonacci(int n) {
        if(n==0) return 0;
        if(n==1 || n==2) return 1;
        return solveTab(n);
    }
};