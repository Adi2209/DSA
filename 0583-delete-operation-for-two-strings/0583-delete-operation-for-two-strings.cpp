class Solution {
private:
    int lcs(string& word1,string& word2,int size1,int size2){
        vector<vector<int>> dp(size1+1,vector<int>(size2+1,0));
        
        for(int i=size1-1;i>=0;i--){
            for(int j=size2-1;j>=0;j--){
                int ans=0;
                if(word1[i]==word2[j]){
                  ans=1+dp[i+1][j+1];
                }
                else{
                  ans=max(dp[i+1][j],dp[i][j+1]);
                }
                dp[i][j]=ans;
            }   
        }
        return dp[0][0];
    }
public:
    int minDistance(string word1, string word2) {
        int size1=word1.size();
        int size2=word2.size();
        return size1+size2-2*lcs(word1,word2,size1,size2);
    }
};