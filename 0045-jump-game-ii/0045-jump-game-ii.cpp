class Solution {
private:
    int solveRec(int ind,vector<int>& nums,vector<int>& dp){
        if(ind>=nums.size()-1) return 0;
        if(dp[ind]!=-1) return dp[ind];
        int steps=nums.size();//max steps to reach the dest
        //take
        for(int i=ind+1;i<=ind+nums[ind];i++){
            steps=min(steps,1+solveRec(i,nums,dp));
        }
        return dp[ind]=steps;
    }
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n+1,-1);
        return solveRec(0,nums,dp);
    }
};