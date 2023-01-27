class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        //first we will find a breakpoint i.e. nums[i+1]>nums[i];
        int n=nums.size();
        int breakPoint=-1;
        
        for(int ind=n-2;ind>=0;ind--){
            if(nums[ind]<nums[ind+1]){
                breakPoint=ind;
                break;
            }
        }
        //now if no breakpoint then reverse the array and get the ans
        if(breakPoint==-1) reverse(nums.begin(),nums.end());
        //finding the element with whom we can swap
        else{
            for(int ind=n-1;ind>breakPoint;ind--){
                if(nums[ind]>nums[breakPoint]){
                    swap(nums[ind],nums[breakPoint]);
                    reverse(nums.begin()+breakPoint+1,nums.end());
                    break;
                }
            }
        }
        
        
    }
};