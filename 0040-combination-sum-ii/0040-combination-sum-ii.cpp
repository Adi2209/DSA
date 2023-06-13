class Solution {
private:
    void solve(int ind, int target, vector<vector<int>>& ans,vector<int>& res, int n,vector<int>& candidates ){
        if(target==0){
            ans.push_back(res);
            return;
        }
        for(int i=ind;i<n;i++){
            if(i!=ind && candidates[i]==candidates[i-1]) continue;
            if(candidates[i]>target) continue;
            res.push_back(candidates[i]);
            solve(i+1,target-candidates[i],ans,res,n,candidates);
            res.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> res;
        int n=candidates.size();
        sort(candidates.begin(),candidates.end());
        solve(0,target,ans,res,n,candidates);
        return ans;
    }
};