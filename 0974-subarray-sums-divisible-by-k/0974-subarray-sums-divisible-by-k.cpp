class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n=nums.size();
        int sum=0,cnt=0;
        unordered_map<int,int> mp;
        mp[0]=1;
        for(int ind=0;ind<n;ind++){
            sum+=nums[ind];
            int rem=sum%k;
            if(rem<0) rem+=k;
            //add all the values of rem to the count
            if(mp.find(rem)!=mp.end()) cnt+=mp[rem];       
            mp[rem]++;
        }
        return cnt;
    }
};