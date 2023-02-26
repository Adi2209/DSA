class Solution {
private:
    int solveTab(string word1,string word2,int size1,int size2){
        
        // vector<vector<int>> dp(size1+1,vector<int>(size2+1,0));
        
        vector<int> curr(size2+1,0);
        vector<int> next(size2+1,0);
        
        for(int ind=0;ind<size2;ind++){
            next[ind]=size2-ind;
        }
  
        for(int ind1=size1-1;ind1>=0;ind1--){
            for(int ind2=size2-1;ind2>=0;ind2--){
                //base case here-->
                curr[size2]=size1-ind1;
                
                int minSteps=0;
                
                if(word1[ind1]==word2[ind2]){
                    minSteps=next[ind2+1];
                }
                else{
                    //insert
                    int insertCh=1+curr[ind2+1];
                    //delete
                    int deleteCh=1+next[ind2];
                    //replace
                    int replaceCh=1+next[ind2+1];

                    minSteps=min(insertCh,min(deleteCh,replaceCh));
                }
                 curr[ind2]=minSteps;
            }
            next=curr;
        }
        return next[0];
    }
public:
    int minDistance(string word1, string word2) {
        int size1=word1.size();
        int size2=word2.size();
        if(size1==0) return size2;
        if(size2==0) return size1;
        return solveTab(word1,word2,size1,size2);
    }
};