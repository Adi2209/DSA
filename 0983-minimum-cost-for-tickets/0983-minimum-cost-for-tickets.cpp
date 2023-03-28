class Solution {
private:
    int solveTab(vector<int>& days,vector<int>& costs,int n){
        
        vector<int> dp(n+1,INT_MAX);//INT_MAX beacuse we need to find the min
        
        dp[n]=0;//recursion's base case
        //we will go from bottom to up 
        for(int k=n-1;k>=0;k--){
        //1 day pass
        int option1=costs[0]+dp[k+1];
        
        //7 day pass
        //moving i to 7 + idx
        int i;
        for(i=k;i<n && days[i]<days[k]+7;i++);
            
        int option2=costs[1]+dp[i];
        
        //30 day pass
        for(i=k;i<n && days[i]<days[k]+30;i++);
            
        int option3=costs[2]+dp[i];
        
        dp[k]=min(option1,min(option2,option3));
            
        }
        return dp[0];
    }
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        // vector<int> dp(days.size()+1,-1);
        // return solveMem(days,costs,0,dp);
        return solveTab(days,costs,days.size());      
    }
};