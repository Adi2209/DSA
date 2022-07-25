class Solution {
private:
    void solve(int idx,int n,vector<int>& current,int k,vector<vector<int>>& ans){
        //base case
        if(current.size()==k){
            ans.push_back(current);
            return;
        }
        //solve for one
        for(int i=idx;i<n+1;i++){
            current.push_back(i);
            solve(i+1,n,current,k,ans);
            current.pop_back();//backtracking
        }
    }
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> current;
        vector<vector<int>> ans;
        solve(1,n,current,k,ans);
        
        return ans;
        
    }
};