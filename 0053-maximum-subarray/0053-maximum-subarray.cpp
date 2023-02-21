class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum=nums[0],currSum=0;
        // kadane's algo
        for(auto &it:nums){
            currSum+=it;
            maxSum=max(maxSum,currSum);
            if(currSum<0) currSum=0;
        }
        return maxSum;
    }
};