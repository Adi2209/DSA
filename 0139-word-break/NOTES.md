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
// int dp[301];
// memset(dp,-1,sizeof dp);
unordered_map<string,int> mp;
for(auto& idx:wordDict) mp[idx];
// return solve(s,0,mp,dp);
return solveTab(s,mp);
}
};