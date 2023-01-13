class Solution {
private:
    int solve(int n,vector<int>& dp){
        if(n==0 || n==1) return 1;
        
        if(dp[n]!=-1) return dp[n];
        
        int maxi=0;
        
        for(int ind=1;ind<n;ind++){
            int temp=max(ind*(n-ind), ind * solve(n-ind,dp));
            maxi=max(maxi,temp);
        }
        return dp[n]=maxi;
    }
public:
    int integerBreak(int n) {
        vector<int> dp(n+1,-1);
        return solve(n,dp);
    }
};