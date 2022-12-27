class Solution {
private:
    int solve(vector<int>& coins,int amt,vector<int>& dp){
        if(amt==0) return 0;//bina coin ke 0 ban jaayega
        if(amt<0) return INT_MAX;
        if(dp[amt]!=-1) return dp[amt];
        
        int mini=INT_MAX;
        
        for(int i=0;i<coins.size();i++){
            if(amt>=coins[i])
                mini=min(mini+0LL,1LL+solve(coins,amt-coins[i],dp));
        }
        return dp[amt]=mini;
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(1e4+1,-1);
        int ans=solve(coins,amount,dp);
        return ans==INT_MAX ? -1: ans;
    }
};