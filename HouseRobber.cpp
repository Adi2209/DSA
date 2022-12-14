class Solution {
public:
    int rob(vector<int>& nums) {
       //tabulation 
        int prev1=nums[0];
        int prev2=0;
        
        if(nums.size()==1) return nums[0];
        int ans=0;
        
        for(int i=1;i<nums.size();i++){
            int ele=nums[i];
            ans=max(prev1,prev2+nums[i]);
            prev2=prev1;
            prev1=ans;
            
        }
        return ans;
    }
};
