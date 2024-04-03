class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int size = nums.size();
        int prefix=1,suffix = 1;
        int maxProduct = nums[0];
        
        for(int ind = 0;ind<size;ind ++){
            if(prefix==0) prefix = 1;
            if(suffix==0) suffix = 1;
            prefix*=nums[ind];
            suffix*=nums[size-ind-1];
            maxProduct = max(maxProduct,max(suffix,prefix));
        }
        return maxProduct;
    }
};