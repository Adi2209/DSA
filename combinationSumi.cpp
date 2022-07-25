class Solution {
private:
    void solve(int idx,int target,vector<int>& arr,vector<vector<int>>& ans,vector<int>& current){
        //base case
        if(idx==arr.size()){
            if(target==0){
                ans.push_back(current);
            }
            return;
        }
        
        if(arr[idx]<=target){
            current.push_back(arr[idx]);
            solve(idx,target-arr[idx],arr,ans,current);
            current.pop_back();
        }
        solve(idx+1,target,arr,ans,current);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> res;
        solve(0,target,candidates,ans,res);
        return ans;
        
    }
};