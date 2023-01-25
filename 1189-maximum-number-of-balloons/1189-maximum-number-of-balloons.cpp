class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char,int> mp;
        
        for(auto it:text) mp[it]++;
        string baloon="baloon";
        int ans=0;
        for(int i=1;i<text.size();i++){
            if(mp['b']>=i*1 && mp['a']>=i*1 && mp['l']>=i*2 && mp['o']>=i*2 && mp['n']>=i*1)
            ans++;
        }
        return ans;
    }
};