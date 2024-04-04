class Solution {
private:
    int solve(int n,vector<int>& memo){
        // base case
        if(n==0 || n==1) return 1;
        if(memo[n]!=-1) return memo[n];
        return memo[n]=solve(n-1,memo)+solve(n-2,memo);
    }
public:
    int climbStairs(int n) {
        vector<int> memo(n+1,-1);
        return solve(n,memo);
    }
};