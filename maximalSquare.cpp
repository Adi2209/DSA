class Solution {
private:
    int solve(vector<vector<char>>& matrix,int i,int j,int& maxi){
        
        //base case
        if(i>=matrix.size() || j>=matrix[0].size()) return 0;
        
        int right=solve(matrix,i,j+1,maxi);
        int diag=solve(matrix,i+1,j+1,maxi);
        int down=solve(matrix,i+1,j,maxi);
        
        
        if(matrix[i][j]=='1'){
            int ans=1+ min(right,min(down,diag));
            maxi=max(ans,maxi);
            return ans;
        }
        else{
            return 0;
        }
    }
    int solveMem(vector<vector<char>>& matrix,int i,int j,int& maxi,vector<vector<int>>& dp){
        
        //base case
        if(i>=matrix.size() || j>=matrix[0].size()) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int right=solveMem(matrix,i,j+1,maxi,dp);
        int diag=solveMem(matrix,i+1,j+1,maxi,dp);
        int down=solveMem(matrix,i+1,j,maxi,dp);
        
        
        if(matrix[i][j]=='1'){
            dp[i][j]=1+ min(right,min(down,diag));
            maxi=max(dp[i][j],maxi);
            return dp[i][j];
        }
        else{
            return dp[i][j]=0;
        }
    }
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int maxi=0;
        solve(matrix,0,0,maxi);
        // return maxi;
        // int n=matrix.size();
        // int m=matrix[0].size();
        // vector<vector<int>> dp(n,vector<int>(m,-1));
        //  solveMem(matrix,0,0,maxi,dp);
        return maxi*maxi;
    }
};
