class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(),s.end());
        int ind=0;
        while(ind<s.size()){
            if(s[ind]!=' '){
                int subStrLen=ind;
                while(subStrLen<s.size() && s[subStrLen]!=' ') subStrLen++;
                reverse(s.begin()+ind,s.begin()+subStrLen);
                ind=subStrLen+1;
            }
            else s.erase(ind,1);
        }
        if (s.back() == ' ') s.pop_back();
        return s;
    }
};