class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        unordered_map<char,int> mp,ms;
        int m=p.size(),n=s.size();
        //including the string p and first window of s in the respective maps
        for(int ind=0;ind<m;ind++){
            mp[p[ind]]++;
            ms[s[ind]]++;
        }
        for(int ind=m;ind<n;ind++){
            if(ms==mp) ans.push_back(ind-m);
            //adding next char
            ms[s[ind]]++;
            //removing the previous character
            ms[s[ind-m]]--;
            if(ms[s[ind-m]]==0) ms.erase(s[ind-m]);  
        }
        if(ms==mp) ans.push_back(n-m);
        return ans;
    }
};