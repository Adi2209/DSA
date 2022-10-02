class Solution {
private:
    #define MOD 1000000007
    int solveTab(int d,int faces,int t){
        
        vector<int> prev(t+1,0);
        vector<int> curr(t+1,0);
        //base case
        prev[0]=1;
        
        
        for(int dices=1;dices<=d;dices++){
            for(int target=1;target<=t;target++){
                long long ans=0;
                for(int i=1;i<=faces;i++){
                    if(target-i>=0)
                        ans=(ans+prev[target-i])%MOD;
                }
                curr[target]=ans;
            }
            prev=curr;
        }
        return prev[t];
    }
public:
    int numRollsToTarget(int n, int k, int target) {
        // vector<vector<long long>> dp(n+1,vector<long long>(target+1,-1));
        // return solveMem(n,k,target,dp);
        
        return solveTab(n,k,target);
        
    }
};
