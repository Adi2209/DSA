class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans;
        for(int i=0;i<n;i++){
            int a=abs(nums[i]);
            if(nums[a-1]<0){
                ans.push_back(a);
            }
            else
                nums[a-1]*=-1;
        }
        return ans;
    }
};