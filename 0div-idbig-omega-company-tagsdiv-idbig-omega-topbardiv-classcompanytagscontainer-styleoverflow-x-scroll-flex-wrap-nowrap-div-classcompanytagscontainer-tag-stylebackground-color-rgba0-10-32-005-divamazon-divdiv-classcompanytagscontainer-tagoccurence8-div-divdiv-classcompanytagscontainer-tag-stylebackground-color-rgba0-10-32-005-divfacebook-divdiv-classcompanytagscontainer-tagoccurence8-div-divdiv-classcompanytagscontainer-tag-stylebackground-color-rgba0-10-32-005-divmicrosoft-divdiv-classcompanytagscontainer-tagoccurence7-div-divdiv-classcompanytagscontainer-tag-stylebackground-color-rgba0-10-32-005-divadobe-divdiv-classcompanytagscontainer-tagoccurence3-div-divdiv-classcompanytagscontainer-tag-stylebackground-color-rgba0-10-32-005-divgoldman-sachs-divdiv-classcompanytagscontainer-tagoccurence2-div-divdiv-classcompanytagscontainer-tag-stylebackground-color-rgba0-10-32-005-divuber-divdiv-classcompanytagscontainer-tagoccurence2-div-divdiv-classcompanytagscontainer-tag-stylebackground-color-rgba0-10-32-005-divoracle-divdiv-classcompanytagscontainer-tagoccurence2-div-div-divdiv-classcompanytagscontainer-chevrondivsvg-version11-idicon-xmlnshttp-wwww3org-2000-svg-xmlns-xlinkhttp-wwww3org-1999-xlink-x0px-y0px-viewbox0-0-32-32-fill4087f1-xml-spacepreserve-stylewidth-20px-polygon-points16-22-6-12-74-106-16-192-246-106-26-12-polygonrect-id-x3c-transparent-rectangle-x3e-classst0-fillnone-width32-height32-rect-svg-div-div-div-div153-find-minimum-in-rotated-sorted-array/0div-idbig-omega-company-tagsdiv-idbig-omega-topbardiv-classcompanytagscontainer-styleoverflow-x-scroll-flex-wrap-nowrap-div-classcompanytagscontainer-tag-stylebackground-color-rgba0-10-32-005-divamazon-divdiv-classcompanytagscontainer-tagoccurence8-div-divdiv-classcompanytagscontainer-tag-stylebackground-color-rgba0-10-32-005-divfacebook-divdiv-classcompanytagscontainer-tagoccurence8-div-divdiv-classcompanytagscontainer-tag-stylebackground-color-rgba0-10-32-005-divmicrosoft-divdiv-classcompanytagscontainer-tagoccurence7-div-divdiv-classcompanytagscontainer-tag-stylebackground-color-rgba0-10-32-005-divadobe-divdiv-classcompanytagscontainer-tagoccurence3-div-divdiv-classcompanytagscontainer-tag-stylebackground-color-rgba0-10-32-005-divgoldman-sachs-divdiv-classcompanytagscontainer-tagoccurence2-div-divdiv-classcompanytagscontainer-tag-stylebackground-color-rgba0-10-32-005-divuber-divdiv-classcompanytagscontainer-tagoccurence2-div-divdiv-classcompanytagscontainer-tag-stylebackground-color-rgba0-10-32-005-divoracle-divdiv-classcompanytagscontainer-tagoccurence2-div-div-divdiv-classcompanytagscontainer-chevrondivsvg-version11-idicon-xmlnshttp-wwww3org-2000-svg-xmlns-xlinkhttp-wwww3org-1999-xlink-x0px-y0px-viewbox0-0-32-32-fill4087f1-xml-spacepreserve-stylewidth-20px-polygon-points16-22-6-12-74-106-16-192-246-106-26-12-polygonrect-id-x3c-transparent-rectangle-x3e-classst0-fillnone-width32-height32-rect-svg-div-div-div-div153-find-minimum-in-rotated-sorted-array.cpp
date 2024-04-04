class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        int low=0,high=n-1;
        int mini=1e9;
        while(low<=high){
            int mid=low+(high-low)/2;
            //if the earch space is already sorted
            if(nums[low]<=nums[high]){
                mini=min(mini,nums[low]);
                break;
            }
            if(nums[low]<=nums[mid]){
                //left half is sorted
                mini=min(mini,nums[low]);
                low=mid+1;
            }
            else{
                mini=min(mini,nums[mid]);
                high=mid-1;
            }
        }
        return mini;
    }
};