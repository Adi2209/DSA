class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n=gain.size();
        vector<int> res(n+1);
        res[0]=0;
        for(int ind=0;ind<n;ind++){
            res[ind+1]=res[ind]+gain[ind];
        }
        int ans=INT_MIN;
        for(auto it:res){
            ans=max(ans,it);
        }
        return ans;
    }
};