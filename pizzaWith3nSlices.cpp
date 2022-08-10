class Solution {
private:
    int solveMem(int index,int endIndex,vector<int>& slices,int n,vector<vector<int>>& dp){
        
        //base case
        if(n==0 || index>endIndex) return 0;
        
        if(dp[index][n]!=-1) return dp[index][n];
        
        int take = slices[index] + solveMem(index+2,endIndex,slices,n-1,dp);
        int notTake = 0 + solveMem(index+1,endIndex,slices,n,dp);
        
        return dp[index][n]=max(take,notTake);
    }
public:
    int maxSizeSlices(vector<int>& slices) {
        int k=slices.size();
        vector<vector<int>> dp1(k,vector<int>(k,-1));
        int case1=solveMem(0,k-2,slices,k/3,dp1);
        vector<vector<int>> dp2(k,vector<int>(k,-1));
        int case2=solveMem(1,k-1,slices,k/3,dp2);
        return max(case1,case2);
    }
};
