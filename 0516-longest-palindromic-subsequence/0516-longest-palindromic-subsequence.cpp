class Solution {
private:
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
    int longestPalindromeSubseq(string s) {
                //we will just reverse the string t and then find the LCS this will give the  answer (LPS)
        string t=s;
        reverse(t.begin(),t.end());
        return solveTab(s,t);
    }
};