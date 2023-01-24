class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size();
        int k=n/3;
        vector<int> ans;
        unordered_map<int,int> mp;
        for(auto &i:nums) mp[i]++;
        for(auto &i:mp) if(i.second>k) ans.push_back(i.first);
        return ans;
    }
};