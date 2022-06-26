class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        unordered_map<int,int> mp;
        
        for(int i=0;i<nums.size();i++){
            if (mp.find(target-nums[i]) != mp.end())
                return {mp[target-nums[i]],i};
             mp[nums[i]]=i;//mapping the value with the index in the map
            
        }
        return {};
    }
};