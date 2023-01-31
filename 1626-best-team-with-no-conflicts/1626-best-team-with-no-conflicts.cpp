class Solution {
private:
    int solve(int ind,vector<int>& scores,vector<int>& ages,int n,int maxAge,vector<pair<int,int>>& team,
    vector<vector<int>>& dp){
        //base case
        if(ind>=n) return 0;
        if(dp[ind][maxAge]!=-1) return dp[ind][maxAge];
        if(team[ind].second>=maxAge){
            //take,not take
            int take=team[ind].first+solve(ind+1,scores,ages,n,team[ind].second,team,dp);
            int notTake=solve(ind+1,scores,ages,n,maxAge,team,dp);
            return dp[ind][maxAge]= max(take,notTake);
        }
        else
            return solve(ind+1,scores,ages,n,maxAge,team,dp);
    }
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        pair<int,int> p;
        vector<pair<int,int>> team;
        int n=scores.size();
        for(int ind=0;ind<n;ind++){
            team.push_back({scores[ind],ages[ind]});
        }
        sort(team.begin(),team.end());
        int maxAge=0;
        vector<vector<int>> dp(1001,vector<int>(1001,-1));
        return solve(0,scores,ages,n,maxAge,team,dp);
    }
};