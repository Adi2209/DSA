class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int,int> mp;
        int n=nums.size();
        for(auto it:nums) mp[it]++;
        int maxi=0;
        for(auto it: mp) maxi=max(it.second,maxi);
        if(maxi==1) return 1;
        int ans=INT_MAX;
        for(auto it: mp){
            if(it.second==maxi){
                int left=0, right=n-1;
                while(left<=right && nums[left]!=it.first) left++;
                while(left<=right && nums[right]!=it.first) right--;
                ans=min(ans,right-left+1);
            }
        }
        return ans;
    }
};