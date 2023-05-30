class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum=INT_MIN,currSum=0;
        int n=nums.size();
        
        for(int ind=0;ind<n;ind++){
            currSum+=nums[ind];
            if(currSum>maxSum) maxSum=currSum;
            if(currSum<0) currSum=0;   
        } 
        return maxSum;
    }
};