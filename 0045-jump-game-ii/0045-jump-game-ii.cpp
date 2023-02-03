class Solution {
private:
    int solveRec(int ind, vector<int>& nums,vector<int>& dp){
        if(ind>=nums.size()-1) return 0;
        if(dp[ind]!=-1) return dp[ind];
        //take
        int steps=nums.size();
        for(int i=ind+1; i<=ind+nums[ind]; i++){
            steps=min(steps, 1+solveRec(i, nums,dp));
        }
        return dp[ind]=steps;
    }
public:
    int jump(vector<int>& nums) {
        vector<int> dp(nums.size()+1,-1);
        return solveRec(0,nums,dp);
    }
};