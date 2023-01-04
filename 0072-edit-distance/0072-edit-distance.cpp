class Solution {
private:
    int solveRec(string word1, string word2,int size1,int size2,int ind1,int ind2,vector<vector<int> >& dp){
        //base case
        if(ind1==size1){
            return size2-ind2;
        }
        if(ind2==size2){
            return size1-ind1;
        }
        if(dp[ind1][ind2]!=-1) return dp[ind1][ind2];
        int minSteps=0;
        if(word1[ind1]==word2[ind2]){
            return solveRec(word1,word2,size1,size2,ind1+1,ind2+1,dp);
        }
        else{
            //insert
            int insertCh=1+solveRec(word1,word2,size1,size2,ind1,ind2+1,dp);
            //delete
            int deleteCh=1+solveRec(word1,word2,size1,size2,ind1+1,ind2,dp);
            //replace
            int replaceCh=1+solveRec(word1,word2,size1,size2,ind1+1,ind2+1,dp);
                
            minSteps=min(insertCh,min(deleteCh,replaceCh));
        }
        return dp[ind1][ind2]=minSteps;
    }
public:
    int minDistance(string word1, string word2) {
        int size1=word1.size();
        int size2=word2.size();
        vector<vector<int>> dp(size1,vector<int>(size2,-1));
        return solveRec(word1,word2,size1,size2,0,0,dp);
    }
};