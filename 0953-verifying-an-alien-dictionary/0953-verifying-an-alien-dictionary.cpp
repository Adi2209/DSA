class Solution {
private:
    bool isValid(string &s1,string &s2,unordered_map<char,int>& mp){
        int n=min(s1.size(),s2.size());
        for(int ind=0;ind<n;ind++){
            if(mp[s1[ind]]<mp[s2[ind]]) return true;
            else if(mp[s1[ind]]>mp[s2[ind]]) return false;
        }
        if(s1.size()>s2.size())return false;
        return true;
    }
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char,int> mp;
        //char ->index
        
        for(int ind=0;ind<order.size();ind++){
            mp[order[ind]]=ind+1;
        }
        for(int ind=1;ind<words.size();ind++){
            if(!isValid(words[ind-1],words[ind],mp)) return false;
        }
        return true;
    }
};