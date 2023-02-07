class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left=0,right=0,n=nums.size();
        int ones=0,zeroes=0,maxLen=0;
        
        while(right<n){
            if(nums[right]==0) zeroes++;
            while(zeroes>k){
                if(nums[left]==0) zeroes--;
                left++;
            }
            maxLen=max(maxLen,right-left+1);
            right++;
        }
        return maxLen;
    }
};