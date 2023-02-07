class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left=0,right=0,n=s.size();
        int maxLen=0;
        unordered_map<char,int> mp;
        while(right<n){
            mp[s[right]]++;
            while(mp[s[right]]>1){
                mp[s[left]]--;
                left++;
            }
            right++;
            maxLen=max(maxLen,right-left);
        }
        return maxLen;
    }
};