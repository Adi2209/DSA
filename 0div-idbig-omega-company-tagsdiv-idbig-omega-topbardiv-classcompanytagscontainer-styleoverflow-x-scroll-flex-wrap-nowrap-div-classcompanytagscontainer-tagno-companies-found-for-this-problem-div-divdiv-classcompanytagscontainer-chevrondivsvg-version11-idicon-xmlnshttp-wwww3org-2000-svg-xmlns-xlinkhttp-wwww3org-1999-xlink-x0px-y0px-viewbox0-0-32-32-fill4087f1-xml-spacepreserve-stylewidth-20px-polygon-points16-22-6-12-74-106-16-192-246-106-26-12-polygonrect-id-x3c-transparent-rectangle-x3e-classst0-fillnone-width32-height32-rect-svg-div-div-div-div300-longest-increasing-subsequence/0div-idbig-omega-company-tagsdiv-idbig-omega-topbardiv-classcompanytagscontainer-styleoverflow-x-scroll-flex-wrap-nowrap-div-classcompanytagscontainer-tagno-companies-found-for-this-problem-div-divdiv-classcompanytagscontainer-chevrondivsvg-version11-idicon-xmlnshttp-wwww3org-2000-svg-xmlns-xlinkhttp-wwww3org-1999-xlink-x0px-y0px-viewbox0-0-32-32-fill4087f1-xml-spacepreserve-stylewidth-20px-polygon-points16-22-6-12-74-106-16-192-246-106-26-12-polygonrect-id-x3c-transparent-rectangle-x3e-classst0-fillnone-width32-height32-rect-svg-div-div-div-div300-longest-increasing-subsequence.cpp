class Solution {
private:
    int solveMem(vector<int>& nums,int curr,int prev,vector<vector<int>>& dp){
        int n=nums.size();
        //base case
        if(curr==n)
            return 0;
        if(dp[curr][prev+1]!=-1) return dp[curr][prev+1];
        //include
        int include=0;
        if(prev==-1 || nums[prev]<nums[curr])
            include=1+solveMem(nums,curr+1,curr,dp);
        int exclude=0+solveMem(nums,curr+1,prev,dp);
        
        return dp[curr][prev+1]=max(exclude,include);//prev+1 so that we don't add -1 to the index
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        
        vector<vector<int>> dp(n,vector<int> (n+1,-1));
        return solveMem(nums,0,-1,dp);
    }
};