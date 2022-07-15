class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.length();
        
        int l=0;
        int r=0;
        int maxCnt=0;
        int ans=0;
        unordered_map<char,int>mp;
        while(r<n){
            mp[s[r]]++;
            maxCnt=max(maxCnt,mp[s[r]]);
            
            int currLen=r-l+1;//currnet length of the window
            
            //if the curr window has more than k replacable items case
            if(currLen-maxCnt>k){
                mp[s[l]]--;
                l++;//contraction of the window  
            }
            currLen=r-l+1;
            ans=max(ans,currLen);
            r++;
        }
        return ans;
        
    }
};