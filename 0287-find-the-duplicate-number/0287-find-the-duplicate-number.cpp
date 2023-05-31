class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n=nums.size();
        for(int ind=0;ind<n;ind++){
            int element=abs(nums[ind]);
            if(nums[element-1]<0){
                return element;
            }
            else
                nums[element-1]*=-1;
            
        }
        return -1;
    }
};