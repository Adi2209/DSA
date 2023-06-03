class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        int j=0;
        for(int ind=1;ind<n;ind++){
            if(nums[ind]!=nums[j]){
                j++;
                nums[j]=nums[ind];
            }
        }
        return j+1;
    }
};