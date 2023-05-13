#define mod 1000000007
class Solution {
private:
    int solve(int idx,int low,int high,int zero,int one,vector<int>& dp){
        
        if(idx>=high)return 0;
        if(dp[idx]!=-1)return dp[idx];

        long long a= solve(idx+zero,low,high,zero,one,dp);
         if(zero+idx>=low and zero+idx<=high)a++;
        
        long long b= solve(idx+one,low,high,zero,one,dp);
         if(one+idx>=low and one+idx<=high)b++;
        
        return dp[idx]=(a+b)%mod;
    }
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<int> dp(high+1,-1);
        return solve(0,low,high,zero,one,dp);
    }
};

