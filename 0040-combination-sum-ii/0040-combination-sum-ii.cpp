class Solution {
private:
    void solve(int idx,int target,vector<int>& arr,vector<vector<int>>& ans,vector<int>& current){
        //base case
            if(target==0){
                ans.push_back(current);
                return;
            }
        
        for(int i=idx;i<arr.size();i++){
            if(i>idx && arr[i]==arr[i-1]) continue;
            if(arr[i]>target) break;
            current.push_back(arr[i]);
            solve(i+1,target-arr[i],arr,ans,current);
            current.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());//sort the given candidates vector 
        vector<vector<int>> ans;
        vector<int> res;
        solve(0,target,candidates,ans,res);
        return ans;
    }
};