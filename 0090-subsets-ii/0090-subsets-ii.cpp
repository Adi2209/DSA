class Solution {
private:
    void solve(int ind,vector<int>& res,vector<vector<int>>& ans, vector<int>& nums, int n){
        
        ans.push_back(res);
        
        for(int i=ind;i<n;i++){
            if(i>ind && nums[i]==nums[i-1]) continue;
            res.push_back(nums[i]);
            solve(i+1,res,ans,nums,n);
            res.pop_back();
        }
        
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int> > ans;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<int> res;
        solve(0,res,ans,nums,n);
        return ans;
    }
};