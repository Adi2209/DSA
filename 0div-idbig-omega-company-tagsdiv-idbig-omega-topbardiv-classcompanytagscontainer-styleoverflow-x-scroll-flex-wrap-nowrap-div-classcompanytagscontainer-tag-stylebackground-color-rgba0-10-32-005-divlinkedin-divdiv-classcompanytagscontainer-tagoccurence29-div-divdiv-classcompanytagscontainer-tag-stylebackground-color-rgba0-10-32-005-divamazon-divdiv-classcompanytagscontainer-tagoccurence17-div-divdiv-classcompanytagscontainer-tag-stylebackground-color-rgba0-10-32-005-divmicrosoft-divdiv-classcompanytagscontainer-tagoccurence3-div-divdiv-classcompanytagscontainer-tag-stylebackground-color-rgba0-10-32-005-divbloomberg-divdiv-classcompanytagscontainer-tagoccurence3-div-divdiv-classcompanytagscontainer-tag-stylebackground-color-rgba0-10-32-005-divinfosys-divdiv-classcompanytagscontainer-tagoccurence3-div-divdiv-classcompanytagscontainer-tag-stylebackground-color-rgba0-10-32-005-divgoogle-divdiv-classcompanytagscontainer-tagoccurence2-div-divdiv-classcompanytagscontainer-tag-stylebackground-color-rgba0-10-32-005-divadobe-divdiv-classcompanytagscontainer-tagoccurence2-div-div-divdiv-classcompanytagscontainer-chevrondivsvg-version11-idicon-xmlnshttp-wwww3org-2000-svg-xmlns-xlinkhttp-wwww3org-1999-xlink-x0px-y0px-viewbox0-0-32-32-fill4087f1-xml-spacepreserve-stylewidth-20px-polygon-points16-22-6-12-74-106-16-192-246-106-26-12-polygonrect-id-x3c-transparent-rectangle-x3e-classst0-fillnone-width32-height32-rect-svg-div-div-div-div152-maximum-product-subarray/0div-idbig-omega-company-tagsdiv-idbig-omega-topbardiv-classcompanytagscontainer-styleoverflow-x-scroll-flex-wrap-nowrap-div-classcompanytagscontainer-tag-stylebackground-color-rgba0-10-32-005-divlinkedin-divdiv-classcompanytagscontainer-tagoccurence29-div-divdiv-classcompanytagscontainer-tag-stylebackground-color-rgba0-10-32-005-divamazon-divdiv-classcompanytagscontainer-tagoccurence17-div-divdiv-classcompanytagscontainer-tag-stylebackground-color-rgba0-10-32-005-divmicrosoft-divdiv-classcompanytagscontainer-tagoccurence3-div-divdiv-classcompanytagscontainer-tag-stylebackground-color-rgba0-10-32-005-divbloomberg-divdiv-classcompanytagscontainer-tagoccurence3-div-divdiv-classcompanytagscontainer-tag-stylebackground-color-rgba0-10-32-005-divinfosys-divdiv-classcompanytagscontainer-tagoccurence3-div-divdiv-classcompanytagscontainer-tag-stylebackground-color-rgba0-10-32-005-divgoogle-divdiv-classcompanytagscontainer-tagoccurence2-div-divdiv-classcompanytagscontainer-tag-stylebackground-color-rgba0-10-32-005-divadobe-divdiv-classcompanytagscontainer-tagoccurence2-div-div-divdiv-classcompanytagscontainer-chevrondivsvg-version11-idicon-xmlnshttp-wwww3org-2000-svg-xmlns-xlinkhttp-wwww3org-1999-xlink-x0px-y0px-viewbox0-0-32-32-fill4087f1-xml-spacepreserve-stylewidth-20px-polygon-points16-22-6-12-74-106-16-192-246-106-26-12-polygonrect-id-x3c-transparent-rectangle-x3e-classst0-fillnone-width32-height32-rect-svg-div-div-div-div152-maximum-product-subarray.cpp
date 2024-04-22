class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxProduct = INT_MIN;
        int prefix = 1;
        int suffix = 1;
        int size = nums.size();
        for(int ind = 0;ind<size;ind++){
            prefix*=nums[ind];
            suffix*=nums[size-ind-1];
            maxProduct = max(maxProduct, max(suffix,prefix));
            if(prefix == 0) prefix = 1;
            if(suffix == 0) suffix = 1;
        }
        return maxProduct;
    }
};