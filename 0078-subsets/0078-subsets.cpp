class Solution {
private:
    void solve(int ind,vector<int>& nums,vector<int>& res,vector<vector<int>>& ans){
        if(ind>=nums.size()){
            ans.push_back(res);
            return;
        }
        
        //include
        res.push_back(nums[ind]);
        solve(ind+1,nums,res,ans);
        //exclude
        res.pop_back();
        solve(ind+1,nums,res,ans);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> res;
        solve(0,nums,res,ans);
        return ans;
    }
};