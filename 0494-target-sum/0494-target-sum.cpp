class Solution {
private:
    int solve(int n,vector<int>& nums,int target,int idx){
        
        if(target==0 && idx==n) return 1;
        if(idx>=n) return 0;
        
        int add=solve(n,nums,target-nums[idx],idx+1);
        int sub=solve(n,nums,target+nums[idx],idx+1);
        return add+sub;
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        return solve(n,nums,target,0);
    }
};