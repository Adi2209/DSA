class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char,int> mp;
        unordered_map<char,int> ms;
        int size1=s.size();
        int size2=p.size();
        
        for(int ind=0;ind<size2;ind++){
            ms[s[ind]]++;
            mp[p[ind]]++;
        }
        vector<int> ans;
        for(int ind =size2;ind<size1;ind++){
            if(ms==mp) ans.push_back(ind-size2);
            ms[s[ind]]++;
            ms[s[ind-size2]]--;
            if(ms[s[ind-size2]]==0) ms.erase(s[ind-size2]);
        }
        if(ms==mp) ans.push_back(size1-size2);
        return ans;
    }
};