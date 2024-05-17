class Solution {
private:
    int getLis(int prev,int curr, int n,vector<int>& nums,vector<vector<int>>& dp){
        if(curr==n) return 0;
        
        if(dp[prev+1][curr]!=-1) return dp[prev+1][curr];
        int exclude = getLis(prev,curr+1,n,nums,dp); 
        
        int include =0;
        if( prev ==-1 || nums[curr]> nums[prev]){
            include = 1+ getLis(curr,curr+1,n,nums,dp);
        }
        return dp[prev+1][curr]= max(include,exclude);
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(n+1,vector<int> (n,-1));
        return getLis(-1,0,n,nums,dp);
    }
};