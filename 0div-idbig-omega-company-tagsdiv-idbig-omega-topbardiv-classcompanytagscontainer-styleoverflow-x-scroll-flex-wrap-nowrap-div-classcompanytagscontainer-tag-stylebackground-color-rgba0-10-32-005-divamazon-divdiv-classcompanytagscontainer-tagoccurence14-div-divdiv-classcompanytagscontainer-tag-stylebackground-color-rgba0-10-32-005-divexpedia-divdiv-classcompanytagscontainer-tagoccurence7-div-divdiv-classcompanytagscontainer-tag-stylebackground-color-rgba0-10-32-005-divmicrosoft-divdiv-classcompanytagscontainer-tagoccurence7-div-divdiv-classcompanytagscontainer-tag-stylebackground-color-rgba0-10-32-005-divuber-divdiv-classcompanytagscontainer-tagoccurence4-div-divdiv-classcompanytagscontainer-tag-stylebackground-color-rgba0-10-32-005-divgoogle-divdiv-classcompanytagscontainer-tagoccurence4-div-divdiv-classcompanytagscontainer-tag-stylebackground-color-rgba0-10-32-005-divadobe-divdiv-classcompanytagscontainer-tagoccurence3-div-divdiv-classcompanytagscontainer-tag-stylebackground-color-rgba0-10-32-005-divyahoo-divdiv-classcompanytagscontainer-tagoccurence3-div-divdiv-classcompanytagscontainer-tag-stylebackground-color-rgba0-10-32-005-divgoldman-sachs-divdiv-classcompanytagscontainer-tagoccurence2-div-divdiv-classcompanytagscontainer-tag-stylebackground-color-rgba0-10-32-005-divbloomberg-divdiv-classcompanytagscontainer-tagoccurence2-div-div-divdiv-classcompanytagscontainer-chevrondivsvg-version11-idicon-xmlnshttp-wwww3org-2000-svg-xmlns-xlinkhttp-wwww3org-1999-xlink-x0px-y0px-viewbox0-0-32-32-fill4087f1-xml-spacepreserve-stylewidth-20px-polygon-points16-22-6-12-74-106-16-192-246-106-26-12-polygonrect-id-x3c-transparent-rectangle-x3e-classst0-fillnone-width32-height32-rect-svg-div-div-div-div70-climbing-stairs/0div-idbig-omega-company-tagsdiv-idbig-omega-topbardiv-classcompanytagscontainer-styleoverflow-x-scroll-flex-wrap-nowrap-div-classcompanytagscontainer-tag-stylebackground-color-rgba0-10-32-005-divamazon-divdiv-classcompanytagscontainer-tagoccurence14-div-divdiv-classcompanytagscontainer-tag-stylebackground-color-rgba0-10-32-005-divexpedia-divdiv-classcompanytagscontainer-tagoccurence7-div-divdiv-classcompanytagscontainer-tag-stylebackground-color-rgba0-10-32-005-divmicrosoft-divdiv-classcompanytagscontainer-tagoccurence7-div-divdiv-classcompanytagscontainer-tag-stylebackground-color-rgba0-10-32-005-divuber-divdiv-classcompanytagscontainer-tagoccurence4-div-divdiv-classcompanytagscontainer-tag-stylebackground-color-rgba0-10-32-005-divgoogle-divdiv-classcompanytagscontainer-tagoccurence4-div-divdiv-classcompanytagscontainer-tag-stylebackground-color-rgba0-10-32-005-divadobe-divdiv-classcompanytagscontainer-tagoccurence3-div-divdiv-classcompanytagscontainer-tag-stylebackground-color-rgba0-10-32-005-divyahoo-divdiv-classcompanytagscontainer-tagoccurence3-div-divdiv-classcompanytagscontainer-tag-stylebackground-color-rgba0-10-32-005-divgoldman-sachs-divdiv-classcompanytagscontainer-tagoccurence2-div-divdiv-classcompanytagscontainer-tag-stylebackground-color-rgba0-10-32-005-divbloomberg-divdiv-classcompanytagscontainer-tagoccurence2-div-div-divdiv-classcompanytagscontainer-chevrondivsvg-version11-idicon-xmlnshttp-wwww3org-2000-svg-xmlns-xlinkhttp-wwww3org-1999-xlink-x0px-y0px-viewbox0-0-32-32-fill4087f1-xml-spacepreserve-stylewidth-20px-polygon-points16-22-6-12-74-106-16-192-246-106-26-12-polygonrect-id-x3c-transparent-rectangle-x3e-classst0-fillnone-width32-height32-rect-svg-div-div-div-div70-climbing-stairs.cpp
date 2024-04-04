class Solution {
private:
    int solve(int n){
        // base case
        if(n==0 || n==1) return 1;
        int prev = 1;
        int curr=1;
        for(int ind=2;ind<=n;ind++){
            int temp = curr;
            curr = prev+curr;
            prev = temp;
        }
        return curr;
    }
public:
    int climbStairs(int n) {
        return solve(n);
    }
};