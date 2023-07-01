class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        int maxSum=INT_MIN;
        int sum=0;
        for(int ind=0;ind<n;ind++){
            sum+=nums[ind];
            maxSum=max(sum,maxSum);
            if(sum<0) sum=0;
        }
        return maxSum;
    }
};