class Solution {
public:
    int minNumber(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        unordered_map<int,int> mp;
        for(auto it:nums1) mp[it]++;
        
        for(auto it:nums2){
            if(mp.find(it)!=mp.end()){
                return it;
            }
        }
        if(nums1[0]<nums2[0]){
            return nums1[0]*10+nums2[0];
        }
        else
            return nums2[0]*10+nums1[0];
    }
};