class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int low=0,high=n-1;
        
        while(low<=high){
            int mid=(low+high)>>1;
            if(nums[mid]==target) return mid;
            //if the left side is sorted 
            else if(nums[low]<=nums[mid]){
                //if in the left sorted part
                if(nums[low]<= target && target<=nums[mid]){
                    high=mid-1;
                }
                else low=mid+1;
            }
            // if right side is sorted
            else{
                //if in the right sorted part
                if(nums[mid]<=target && nums[high]>=target){
                    low=mid+1;
                }
                else high=mid-1;
            }
        }
        return -1;
    }
};