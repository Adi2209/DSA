class Solution {
private:
    void solve(int ind,vector<vector<int>>& ans,vector<int>& nums){
        if(ind==nums.size()){
            //no res array because we are changing the in nums only 
            ans.push_back(nums);
            return;
        }
        for(int i=ind;i<nums.size();i++){
            swap(nums[ind],nums[i]);
            solve(ind+1,ans,nums);
            //backtracking (remember that recursion tree ..you will have to nullify the swap ...to avoid problems for the next swap)
            swap(nums[ind],nums[i]);
            
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        solve(0,ans,nums);
        return ans;
    }
};