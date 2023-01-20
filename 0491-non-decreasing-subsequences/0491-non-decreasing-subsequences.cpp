class Solution {
private:
    void solve(int ind,vector<int>& nums,int n,vector<int>& res,set<vector<int>>& st){
        
        //base case
        if(ind>=n){
            if(res.size()>=2){
                st.insert(res);
            }
            return;
        }
        //solving one case for recursion
        // take
        if(!res.size() || nums[ind]>=res.back()){
            res.push_back(nums[ind]);
            solve(ind+1,nums,n,res,st);
            res.pop_back();
        }
        //not take
        solve(ind+1,nums,n,res,st);
        
    }
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> res;
        int n=nums.size();
        set<vector<int>> st;
        solve(0,nums,n,res,st);
        for(auto &it:st){
            ans.push_back(it);
        }
        return ans;
    }
};