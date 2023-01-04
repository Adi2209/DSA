class Solution {
private:
    int solveTab(string word1,string word2,int size1,int size2){
        
        vector<vector<int>> dp(size1+1,vector<int>(size2+1,0));
        
        for(int ind=0;ind<size2;ind++){
            dp[size1][ind]=size2-ind;
        }
        for(int ind=0;ind<size1;ind++){
            dp[ind][size2]=size1-ind;
        }
        for(int ind1=size1-1;ind1>=0;ind1--){
            for(int ind2=size2-1;ind2>=0;ind2--){
                int minSteps=0;
                if(word1[ind1]==word2[ind2]){
                    minSteps=dp[ind1+1][ind2+1];
                }
                else{
                    //insert
                    int insertCh=1+dp[ind1][ind2+1];
                    //delete
                    int deleteCh=1+dp[ind1+1][ind2];
                    //replace
                    int replaceCh=1+dp[ind1+1][ind2+1];

                    minSteps=min(insertCh,min(deleteCh,replaceCh));
                }
                 dp[ind1][ind2]=minSteps;
            }
        }
        return dp[0][0];
    }
public:
    int minDistance(string word1, string word2) {
        int size1=word1.size();
        int size2=word2.size();
        return solveTab(word1,word2,size1,size2);
    }
};