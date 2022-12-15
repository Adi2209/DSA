class Solution {
private:
    int solve(int i,int j,string& s,string& t,vector<vector<int>>& dp){
        if(i ==s.size() || j==t.size()) return 0;
        
        if(dp[i][j]!=-1) return dp[i][j];
        //solve for one case
        int ans=0;
        
        if(s[i]==t[j]){
             ans=1+solve(i+1,j+1,s,t,dp);
        }
        else{
             ans= max(solve(i+1,j,s,t,dp),solve(i,j+1,s,t,dp));
        }
        return dp[i][j]=ans;
    }
    
    int solveTab(string s, string t){
        
        vector<vector<int>> dp(s.size()+1,vector<int>(t.size()+1,0));
        for(int i=s.length()-1;i>=0;i--){
            for(int j=t.length()-1;j>=0;j--){
                int ans=0;
                if(s[i]==t[j]){
                    ans=1+dp[i+1][j+1];
                }
                else{
                    ans= max(dp[i+1][j],dp[i][j+1]);
                }
                 dp[i][j]=ans;
            }
        }
        return dp[0][0];
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        
        // int n=text1.size();
        // int m=text2.size();
        // vector<vector<int>> dp(n,vector<int>(m,-1));
        // return solve(0,0,text1,text2,dp);
        return solveTab(text1,text2);
    }
};