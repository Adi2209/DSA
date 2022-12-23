class Solution {
public:
    int recur(int idx, vector<int>& p, bool buy, vector<vector<int>>& dp){
        if(idx>=p.size()) return 0;
        if(dp[idx][buy]!=-1) return dp[idx][buy]; 
        int profit=0;
        if(buy)
            profit = max(-p[idx]+recur(idx+1, p, false, dp), recur(idx+1, p, true, dp));
        else
            profit = max(p[idx]+recur(idx+2, p, true, dp), recur(idx+1, p, false, dp));
        return dp[idx][buy] = profit;
    }
    
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(), vector<int>(2, -1));
        return recur(0, prices, true, dp);
    }
};