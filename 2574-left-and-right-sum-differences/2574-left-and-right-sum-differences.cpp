class Solution {
public:
    vector<int> leftRigthDifference(vector<int>& nums) {
        int n=nums.size();
        vector<int> left(n, 0), right(n, 0),ans(n,0);
        left[0]= nums[0];
        for(int ind=1; ind<n; ind++){
            left[ind]= left[ind-1]+nums[ind];
        }
        right[n-1]= nums[n-1];
        for(int ind=n-2; ind>=0; ind--){
            right[ind]= right[ind+1] + nums[ind];
        }
        for(int ind=0;ind<n;ind++){
            ans[ind]=abs(left[ind]-right[ind]);
        }
        return ans;
    }
};