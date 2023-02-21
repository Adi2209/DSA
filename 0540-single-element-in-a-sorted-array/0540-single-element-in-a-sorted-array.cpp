class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size();
        int left=0,right=n-1;
        
        while(left<right){
            int mid=left+(right-left)/2;
            int ele;
            if(mid%2==0) ele=mid+1;
            else ele=mid-1;
            if(nums[mid]==nums[ele]) left=mid+1;
            else right=mid;
        }
        return nums[left];
    }
};