class Solution {
public:
    int longestCommonSubsequence(string s, string t) {
        int n=s.size();
        int m=t.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        for(int ind = 0;ind<=n;ind++) dp[ind][0] = 0;
        for(int ind = 0;ind<=m;ind++) dp[0][ind] = 0;
        
        for(int i = 1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[i-1] == t[j-1]) dp[i][j] = 1+ dp[i-1][j-1];
                else dp[i][j] = 0+ max(dp[i][j-1], dp[i-1][j]);
            }
        }
        return dp[n][m];
        
    }
};