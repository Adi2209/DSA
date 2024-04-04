class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int high = n-1, low =0;
        int ans = 1e9;
        
        while(low<=high){
            int mid = low+(high-low)/2;
            if(nums[low]<=nums[high]){
                ans = min(ans,nums[low]);
                break;
            }
            if(nums[low]<=nums[mid]){
                ans = min(ans,nums[mid]);
                low=mid+1;
            }
            else{
                ans = min(ans,nums[mid]);
                high=mid-1;
            }
        }
        return ans;
        
    }
};