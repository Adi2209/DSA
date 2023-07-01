class Solution {
private:
    void solve(int idx,vector<int>& arr, int k,vector<int>& res,int& ans,int n){
        //base case
        if(idx==n){
            int maxi=INT_MIN;
            for(int i=0;i<k;i++){
                maxi=max(maxi,res[i]);
            }
            ans=min(ans,maxi);
            return;
        }
        
        for(int i=0;i<k;i++){
            res[i]+=arr[idx];
            solve(idx+1,arr,k,res,ans,n);
            //backtrack
            res[i]-=arr[idx];
        }
    }
public:
    int distributeCookies(vector<int>& cookies, int k) {
        int n=cookies.size();
        int ans=INT_MAX;
        vector<int> res(k,0);
        solve(0,cookies,k,res,ans,n);
        return ans;
        
    }
};