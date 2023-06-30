class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int> mp{
            {'I',1},
            {'V',5},
            {'X',10},
            {'L',50},
            {'C',100},
            {'D',500},
            {'M',1000},
        };
        int ans=0;
        for(int ind=0;ind+1<s.size();ind++){
            if(mp[s[ind]]>=mp[s[ind+1]]) ans+=mp[s[ind]];
            else ans-=mp[s[ind]];
        }
        ans+=mp[s[s.size()-1]];
        return ans;
    }
};