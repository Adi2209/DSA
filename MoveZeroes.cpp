class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        
        int n=nums.size();
        int j=0;
        int i=0;
            while(i<n && j<n){
            if(nums[i]!=0){
                swap(nums[i],nums[j]);
                i++;
                j++;
            }
            else 
                i++;
        }
    }
};