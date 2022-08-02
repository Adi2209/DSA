class Solution {
private:
    int solve(vector<int> nums,int target,vector<int>& dp){
        
        //base case
        if(target==0) return 1;
        if(target<0) return 0;
        if(dp[target]!=-1) return dp[target];
        int ans=0;
        for(int idx=0;idx<nums.size();idx++){
            ans+=solve(nums,target-nums[idx],dp);
        }
        dp[target]=ans;
        return dp[target]=ans;
    }
public:
  //Recursion+memoization
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target+1,-1);
        return solve(nums,target,dp);
    }
};
