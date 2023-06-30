class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        int breakpoint=-1;
        for(int ind=n-2;ind>=0;ind--){
            if(nums[ind+1]>nums[ind]){
                breakpoint=ind;
                break;
            }
        }
        if(breakpoint==-1){
            reverse(nums.begin(),nums.end());
            return;
        }
        
        for(int ind=n-1;ind>breakpoint;ind--){
            if(nums[ind]>nums[breakpoint]){
                swap(nums[ind],nums[breakpoint]);
                reverse(nums.begin()+breakpoint+1,nums.end());
                break;
            }
        }
    }
};