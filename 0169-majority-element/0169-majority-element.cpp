class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        int ans=0,cnt=0;
        for(int ind=0;ind<n;ind++){
            if(nums[ind]==ans) cnt++;
            else if(cnt==0){
                ans=nums[ind];
                cnt=1;
            }
            else cnt--;
        }
        return ans;
    }
};