class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n,0);
        int product = 1;
        for(int ind=0;ind<n;ind++){
            product*=nums[ind];
            ans[ind] = product; 
        }
        
        product = 1;
        for(int ind=n-1;ind>0;ind--){
            ans[ind] = ans[ind-1]* product;
            product*=nums[ind];
        }
        ans[0]=product;
        return ans;
    }
};