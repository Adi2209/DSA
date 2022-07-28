class Solution {
private:
    int solveTab(vector<int>& coins,int amt){
        
        vector<int> dp(amt+1,INT_MAX);
        dp[0]=0;
        
        for(int i=1;i<=amt;i++){
            //now we will solve for every amt. from 1 to x
            for(int j=0;j<coins.size();j++){
                if(i-coins[j]>=0 && dp[i-coins[j]]!=INT_MAX){//check if it is a valid index
                    dp[i]=min(dp[i],1+dp[i-coins[j]]);
                }
            }
        }
        
        if(dp[amt]==INT_MAX)return -1;
            
        return dp[amt];
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        return solveTab(coins,amount);
    }
};