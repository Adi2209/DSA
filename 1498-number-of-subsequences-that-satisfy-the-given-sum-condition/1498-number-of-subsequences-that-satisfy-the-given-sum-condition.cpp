class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int mod=1000000007;
        int s=0,e=n-1;
        int ans=0;
        
        vector<int> pow(n,1);

        for(int i=1; i<n; i++){
            pow[i] = (pow[i-1] * 2) % mod;   
        }
        
        for(int i=0;i<pow.size();i++) cout<<pow[i]<<" ";
        
        while(s<=e){
            if(nums[s]+nums[e]<=target){
                ans=(ans+pow[e-s])%mod;
                s++;
            }
            else{
                e--;
            }
            
        }
        return ans%mod;
    }
};