class Solution {
public:
    int func(vector<vector<int>>& p,int i,int k,vector<vector<int>>& dp){
        if(i==p.size()) return 0;
        if(dp[i][k]!=-1) return dp[i][k];
        int ans=func(p,i+1,k,dp);
        int a=0;
        for(int j=0;j<p[i].size()&&j<k;j++){
            a+=p[i][j];
            ans=max(ans,a+func(p,i+1,k-j-1,dp));
        }
        return dp[i][k]=ans;
    }
    int maxValueOfCoins(vector<vector<int>>& p, int k) {
        vector<vector<int>> dp=vector<vector<int>>(p.size(),vector<int>(k+1,-1));
        return func(p,0,k,dp);
    }
};