class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        for(int ind=0;ind<nums.size();ind++){
            int ele = abs(nums[ind]);
            if(nums[ele-1]<0) return ele;
            else nums[ele-1]*=-1;
        }
        return -1;       
    }
};