class Solution {
private:
    void solve(int ind,int target,vector<vector<int>>& ans,vector<int>& res, vector<int>& candidates,int n){
        
        if(target==0){
            ans.push_back(res);
            return ;
        }
        
        for(int i=ind;i<n;i++){
            if(candidates[i]<=target){
                res.push_back(candidates[i]);
                solve(i,target-candidates[i],ans,res,candidates,n);
                res.pop_back();
            }
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> res;
        int n=candidates.size();
        solve(0,target,ans,res,candidates,n);
        return ans;
    }
};