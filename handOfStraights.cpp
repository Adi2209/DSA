class Solution {
public:
    bool isNStraightHand(vector<int>& nums, int k) {
        
        int n=nums.size();
        
        if(n%k!=0) return false;
        
        sort(nums.begin(),nums.end());
        
        unordered_map<int,int> mp;
        
        for(auto &idx:nums) mp[idx]++;
        
        for(int i=0;i<n;i++){
            if(mp[nums[i]]==0) continue;
            
            mp[nums[i]]--;
            
            for(int j=1;j<k;j++){
                if(mp[nums[i]+j]==0) return false;
                
                mp[nums[i]+j]--;
            }
        }
        return true;
        
    }
};
