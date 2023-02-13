class Solution {
public:
    int countGoodSubstrings(string s) {
        int n=s.size();
        if(n<3) return 0;
        int start=0,cnt=0;
        unordered_map<char,int> mp;
        mp[s[0]]++;
        mp[s[1]]++;
        
        for(int end=2;end<n;end++){
            mp[s[end]]++;
            if(mp.size()==3) cnt++;
            if(mp[s[start]]>1) mp[s[start]]--;
            else mp.erase(s[start]);
            start++;
        }
        return cnt;
    }
};