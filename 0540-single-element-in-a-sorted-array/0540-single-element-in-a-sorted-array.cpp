class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int ans=nums[0];
        for(int ind=1;ind<nums.size();ind++) ans^=nums[ind];
        return ans;
    }
};