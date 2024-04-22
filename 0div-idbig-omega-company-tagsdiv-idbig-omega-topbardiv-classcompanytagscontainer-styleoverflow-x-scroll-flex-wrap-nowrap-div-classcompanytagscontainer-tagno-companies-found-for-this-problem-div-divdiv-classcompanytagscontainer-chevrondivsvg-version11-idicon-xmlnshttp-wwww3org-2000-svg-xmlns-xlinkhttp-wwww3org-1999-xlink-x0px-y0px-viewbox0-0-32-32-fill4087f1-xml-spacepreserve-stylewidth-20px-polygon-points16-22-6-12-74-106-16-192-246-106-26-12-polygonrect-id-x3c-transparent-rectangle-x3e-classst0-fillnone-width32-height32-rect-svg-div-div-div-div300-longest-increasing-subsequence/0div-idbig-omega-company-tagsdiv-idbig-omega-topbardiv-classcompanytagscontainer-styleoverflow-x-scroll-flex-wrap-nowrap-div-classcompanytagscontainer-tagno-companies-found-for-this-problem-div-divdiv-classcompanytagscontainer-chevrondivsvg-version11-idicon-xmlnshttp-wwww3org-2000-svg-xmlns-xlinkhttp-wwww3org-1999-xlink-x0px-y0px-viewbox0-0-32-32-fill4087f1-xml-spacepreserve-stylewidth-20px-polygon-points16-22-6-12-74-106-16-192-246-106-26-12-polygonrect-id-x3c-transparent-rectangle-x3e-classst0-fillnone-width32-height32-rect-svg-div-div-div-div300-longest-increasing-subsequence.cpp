class Solution {
private:
    int solveRec(vector<int>& nums,int curr,int prev,vector<vector<int>>& dp){
        if(curr == nums.size()) return 0;
        
        if(dp[curr][prev+1] != -1) return dp[curr][prev+1];
        // take
        int include =0;
        if(prev == -1 || nums[prev]< nums[curr]) include = 1+solveRec(nums,curr+1,curr,dp);
        int exclude = 0 + solveRec(nums,curr+1,prev,dp);
        
        return dp[curr][prev+1] = max(include,exclude);
        
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n,vector<int> (n+1,-1));
        return solveRec(nums,0,-1,dp);
    }
};