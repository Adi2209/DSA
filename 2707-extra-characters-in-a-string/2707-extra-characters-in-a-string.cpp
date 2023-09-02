class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) 
    { 
        int n = s.size();
        unordered_map<string, int>mp;
        for (string& word : dictionary) mp[word]++;
        vector<int>dp(n + 1, 0);
    
        for (int index = n - 1; index >= 0; index--) //index denotes the startIdx of current sub problem string
        {
            string currStr = "";
            int minExtra = s.size();
            for (int cutIdx = index; cutIdx < n; cutIdx++)
            {
                currStr.push_back(s[cutIdx]);
                //currStr will be a string from (index to cutIdx)

                //if string not in dictionary, we have to delete as they are extra chars
                int currExtra = (mp.count(currStr))? 0 : currStr.size();
                int nextExtra = dp[cutIdx + 1]; 
                int totalExtra = currExtra + nextExtra;

                minExtra = min(minExtra, totalExtra);
            }
            dp[index] = minExtra;
        }
        return dp[0];
    }
};