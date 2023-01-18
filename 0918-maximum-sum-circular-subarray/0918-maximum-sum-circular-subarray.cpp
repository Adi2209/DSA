class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int total=0,currSum=0,maxSum=-1e9;
        int ans=INT_MIN;
        bool flag=true;
        for(auto it:nums){
            if(it>=0){
                flag=false;
                break;
            }
            ans = max(ans,it);
        }
        if(flag) return ans;
        for(auto &it:nums){
            currSum+=it;
            total+=it;
            maxSum=max(maxSum,currSum);
            if(currSum<0) currSum=0;
        }
        int minSum=1e9;
        currSum=0;
        for(auto &it:nums){
            currSum+=it;
            minSum=min(minSum,currSum);
            if(currSum>0) currSum=0;
        }
        
        int sumLeft=total-minSum;
        ans=max(maxSum,sumLeft);
        return ans;
        
    }
};