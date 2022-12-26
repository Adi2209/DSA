class Solution {
private:
    int solve(string s,int idx,unordered_map<string,int>& mp,int *dp){
        
        if(idx==s.size()) return 1;
        if(dp[idx]!=-1) return dp[idx];
        string temp;
        for(int j=idx;j<s.size();j++){
            temp+=s[j];
            if(mp.find(temp)!=mp.end()){
                if(solve(s,j+1,mp,dp)) return dp[idx]=1;
            }
        }
        return dp[idx]=0;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int dp[301];
        memset(dp,-1,sizeof dp);
        unordered_map<string,int> mp;
        for(auto& idx:wordDict) mp[idx];
        return solve(s,0,mp,dp);
    }
};