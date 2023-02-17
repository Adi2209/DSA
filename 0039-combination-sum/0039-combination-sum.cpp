class Solution {
private:
    void solve(vector<int>& candidates,int idx,int target,vector<vector<int>>& ans,vector<int>& res){
        
        //base case
        if(target==0){
            ans.push_back(res);
            return;
        }
        for(int i=idx;i<candidates.size();i++){
            if(candidates[i]<=target){
                res.push_back(candidates[i]);
                solve(candidates,i,target-candidates[i],ans,res);
                res.pop_back();
            }
            
        }
        
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> res;
        solve(candidates,0,target,ans,res);
        return ans;
    }
};