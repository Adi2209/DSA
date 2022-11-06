// This Code passes all the 62 TestCases on leetcode but takes more time.
class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n=nums.size();
        if(n<=2) return n;
        int ans=0;
        unordered_map<int,int> dp[n+1];
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                int diff=nums[i]-nums[j];
                int cnt=1;
                if(dp[j].count(diff)){
                    cnt=dp[j][diff];
                }
                dp[i][diff]=1+cnt;
                ans=max(ans,dp[i][diff]);
            }
        }
        return ans;
    }
};

___________________________________________________________________________

//Correct Way without TLE

class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size(),ans = 2,diff;//initially the ans will be 2 beacuse atleast 2 numbers will be required for a valid AP
        vector<vector<int>>dp(n,vector<int>(1001,0));
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                diff = nums[j]-nums[i]+500;//negative difference can't be less than -500
                dp[j][diff] = max(2,dp[i][diff]+1);
                ans = max(ans,dp[j][diff]);
            }
        }
        return ans;
    }
};
