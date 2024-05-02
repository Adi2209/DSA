class Solution {
public:
    int findMaxK(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int s=0;
        int e=nums.size()-1;
        while(s<e){
            int sum=nums[s]+nums[e];
            if(sum==0) return nums[e];
            else if(sum<0) s++;
            else e--;
        }
        return -1;
    }
};