class Solution {
public:
    long long minimalKSum(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        long long minSum=((long long)k*(long long)(k+1))/2;
        unordered_map<int,int> mp;
        int maxEle=k+1;
        for(auto it:nums){
            if(mp[it]!=1 && it<maxEle){
                minSum-=it;
                minSum+=maxEle;
                maxEle++;
            }
            mp[it]=1;
        }
        return minSum;
    }
};