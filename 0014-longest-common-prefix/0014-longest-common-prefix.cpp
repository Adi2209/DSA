class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n=strs.size();
        sort(strs.begin(),strs.end());
        string first=strs[0];
        string last=strs[n-1];
        string ans="";
        for(int ind=0;ind<strs[0].size();ind++){
            if(first[ind]==last[ind]) ans+=first[ind];
            else break;
        }
        return ans;
    }
};