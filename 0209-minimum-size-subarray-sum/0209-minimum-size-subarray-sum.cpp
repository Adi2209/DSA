class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        
        int n=nums.size();
        int l=0,r=0;
        int sum=0;
        int ans=INT_MAX;
        
        while(r<n){
            if(sum<target)
                sum+=nums[r];
             if(sum >= target){
                while(l<=r && sum>=target){
                    sum-=nums[l];
                    ans=min(ans,r-l+1);
                    l++;
                }
            }
            r++;
        }
        return ans==INT_MAX ?0:ans;
    }
};