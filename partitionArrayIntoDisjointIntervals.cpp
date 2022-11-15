class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        
        int n=nums.size();
        int leftMax=nums[0];
        int maxi=nums[0];
        int ans=1;
        for(int i=1;i<n;i++){
            if(leftMax>nums[i]){
                leftMax=maxi;
                ans=i+1;
            }
            maxi=max(maxi,nums[i]);
        }
        return ans;
    }
};
