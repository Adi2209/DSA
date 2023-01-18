class Solution {
private:
    void flip(vector<int>&nums){
        for(int ind=0;ind<nums.size();ind++){
            nums[ind]*=-1;
        }
    }
    int kadane(vector<int>& nums){
        int maxSum=nums[0],currSum=0;
        
        for(auto &it:nums){
            currSum+=it;
            maxSum=max(maxSum,currSum);
            if(currSum<0) currSum=0;
        }
        
        return maxSum;
    }
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int sum = kadane(nums);
        flip(nums);
        sum = max(sum,kadane(nums));
        
        return sum;
    }
};