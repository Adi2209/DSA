class Solution {
public:
    int subarrayLCM(vector<int>& nums, int k) {
        int n=nums.size(),ans=0;
        for(int i=0;i<n;i++){
            int currLCM=nums[i];
            for(int j=i;j<n;j++){
                currLCM=lcm(currLCM,nums[j]);
                if(currLCM==k) ans++;
                else if(currLCM>k) break;
            }
        }
        return ans;
    }
};