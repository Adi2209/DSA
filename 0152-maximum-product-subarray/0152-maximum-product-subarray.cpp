class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int suffix=1,prefix=1, n=nums.size();
        int maxProduct=nums[0];
        
        for(int ind=0;ind<n;ind++){
            if(prefix==0) prefix=1;
            if(suffix==0) suffix=1;
            prefix*=nums[ind];
            suffix*=nums[n-ind-1];
            maxProduct=max(maxProduct,max(prefix,suffix));
        }
        return maxProduct;
    }
};