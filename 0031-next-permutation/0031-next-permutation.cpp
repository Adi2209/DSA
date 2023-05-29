class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        int breakpoint=-1;
        for(int ind=n-2;ind>=0;ind--){
            if(nums[ind+1]>nums[ind]){
                //breakpoint found
                breakpoint=ind;
                break;
            }
        }
        //now if no breakpoint found this means that the array is sorted in decreasing order
        //so now we will reverse the array and return it
        if(breakpoint==-1){
            reverse(nums.begin(),nums.end());
        }
        else{
            //if breakpoint found, now find the element greater to the arr[ind] on the right half
            for(int ind=n-1;ind>breakpoint;ind--){
                if(nums[breakpoint]<nums[ind]){
                    swap(nums[breakpoint],nums[ind]);
                    reverse(nums.begin()+breakpoint+1,nums.end());
                    break;
                }
            }
        }        
    }
};