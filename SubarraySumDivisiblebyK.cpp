class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n=nums.size();
        int sum=0,remainder=0,ans=0;
        unordered_map<int,int> mp; //map to store the remainders with their sum 
        mp[0]=1;
        
        for(int i=0;i<n;i++){
            sum+=nums[i];
            remainder=sum%k;
            if(remainder<0){
                remainder+=k;
            }
            
            //check in the map if remainder is alreay present or not
            if(mp.find(remainder)!=mp.end()){
                //add it into result
                ans+=mp[remainder];
            }
            mp[remainder]++;
            
        }
        return ans;
    }
};