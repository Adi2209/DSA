class Solution {
private:
    void solve(int idx,vector<int>& nums,vector<int>& current,vector<vector<int>>& ans){
        //base case;
            ans.push_back(current);
            
        for(int i=idx;i<nums.size();i++){
            if(i>idx && nums[i]==nums[i-1]) continue;
            int ele=nums[i];
            current.push_back(ele);
            solve(i+1,nums,current,ans);
            //backtrack
            current.pop_back();
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
         sort(nums.begin(),nums.end());      //sort the array so that duplicates are adjacent 
        vector<int> current;
        vector<vector<int>> ans;
        solve(0,nums,current,ans);
        return ans;
    }
};