class Solution {
public:
    bool checkIfPangram(string sentence) {
        vector<int> mp(26);
        
        for(auto idx: sentence) mp[idx-'a']++;
        
        for(auto idx:mp){
            if(idx==0) return false;
        }
        
        return true;
    }
};
