class Solution {
private:    
    int solveTab(string s,unordered_map<string,int> mp){
        int dp[301];
        memset(dp,0,sizeof dp);
        int n=s.size();
        dp[n]=1;
        for(int i=n-1;i>=0;i--){
            string temp;
           for(int j=i;j<s.size();j++){
            temp+=s[j];
            if(mp.find(temp)!=mp.end()){
                if(dp[j+1]==1) dp[i]=1;
            }
        }
    }
        return dp[0];
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string,int> mp;
        for(auto& idx:wordDict) mp[idx];
        return solveTab(s,mp);
    }
};