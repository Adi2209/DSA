class Solution {
private:
    int lcs(string& word1,string& word2,int size1,int size2){
        vector<vector<int>> dp(size1+1,vector<int>(size2+1,0));
        
        for(int i=size1-1;i>=0;i--){
            for(int j=size2-1;j>=0;j--){
                int ans=0;
                if(word1[i]==word2[j]){
                  ans=(int)word1[i]+dp[i+1][j+1];
                }
                else{
                  ans=max(dp[i+1][j],dp[i][j+1]);
                }
                dp[i][j]=ans;
            }   
        }
        return dp[0][0];
    }
    int getSum(string &str){
        int sum=0;
        for(int ind=0;ind<str.size();ind++)
            sum+=int(str[ind]);
        return sum;
    }
public:
    int minimumDeleteSum(string s1, string s2) {
        int sum1=getSum(s1);
        int sum2=getSum(s2);
        int size1=s1.size(),size2=s2.size();
        cout<<"Sum1: "<<sum1<<endl;
        cout<<"Sum2: "<<sum2<<endl;;
        
        int lcsSum=lcs(s1,s2,size1,size2);
        cout<<"LCS: "<<lcsSum<<endl;
        return sum1+sum2-2*lcsSum;
    }
};