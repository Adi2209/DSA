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
    
    int solveTab(int n){
        vector<int> dp(n+1,0);
        
        dp[0]=1;
        dp[1]=1;
        
        
        for(int i=2;i<=n;i++){
            int maxi=1;
            for(int ind=1;ind<i;ind++){
            int temp=max(ind*(i-ind), ind * dp[i-ind]);
            maxi=max(maxi,temp);
            }
            dp[i]=maxi;
        }
        
        return dp[n];
    }
public:
    int integerBreak(int n) {
        
        return solveTab(n);
    }
};