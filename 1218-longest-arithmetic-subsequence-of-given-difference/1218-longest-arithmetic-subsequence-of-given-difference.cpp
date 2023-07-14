class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        unordered_map<int,int> dp;
        int ans=0;
        for(int i=0;i<arr.size();i++){
            int temp=arr[i]-difference;
            int tempAns=0;
            
            //check if the ans is present in dp array
            if(dp.find(temp)!=dp.end())
                tempAns=dp[temp];
            
            //updateing the current answer
            dp[arr[i]]=1+tempAns;
            
            //updating the ans
            ans=max(ans,dp[arr[i]]);
            
        }
        return ans;
    }
};