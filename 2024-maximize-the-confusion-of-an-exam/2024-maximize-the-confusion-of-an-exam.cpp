class Solution {
public:
    int maxConsecutiveAnswers(string s, int k) {
        int n=s.size();
        int l=0,r=0;
        unordered_map<char,int> mp;
        int ans=0,maxCnt=0;
        while(r<n){
            // increasing the window size form right
            mp[s[r]]++;
            maxCnt=max(maxCnt,mp[s[r]]);
            int currLen=r-l+1;
            // i fthe currWindow has more than k replacable elements
            if(currLen-maxCnt>k){
                //contracting the window from the left
                mp[s[l]]--;
                l++;
            }
            currLen=r-l+1;
            ans=max(ans,currLen);
            r++;
        }
            
        return ans;
    }
};

