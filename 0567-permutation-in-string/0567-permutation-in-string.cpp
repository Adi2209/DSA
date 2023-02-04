class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int windowLen=s1.size();

        vector<int> mp1(26,0);
        vector<int> mp2(26,0);
        for(auto it:s1) mp1[it-'a']++;
        for(int ind=0;ind<s2.size();ind++){
            mp2[s2[ind]-'a']++;
            if(ind>=s1.size()-1){
                if(mp2==mp1) return true;
                mp2[s2[ind-s1.size()+1]-'a']--;
            }
        }
        return false;
    }
};