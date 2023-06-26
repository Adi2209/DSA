class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()) return false;
        vector<int> freq(26,0);
        
        for(int ind=0;ind<s.size();ind++){
            freq[s[ind]-'a']++;
            freq[t[ind]-'a']--;
        }
        for(auto it:freq){
            if(it!=0) return false;
        }
        return true;
    }
};