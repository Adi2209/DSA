class Solution {
private:
    bool checkConcatenate(string word,unordered_set<string>& st,int minLen,set<string>& tempCache) {
        if(tempCache.find(word)!=tempCache.end()) return true;
        for(int i = minLen; i <= word.length()-minLen; i++) {
            string prefixWord = word.substr(0, i);
            string suffixWord = word.substr(i, word.length()-i);
            if(st.find(prefixWord) != st.end() && (st.find(suffixWord) != st.end() || checkConcatenate(suffixWord,st,minLen,tempCache))){
                tempCache.insert(word);
                return true;
            }
        }
        return false;
    }
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        vector<string> concatenateWords;
        unordered_set<string> st; 
        set<string> tempCache;
        int minLen=1e9;
        for(auto word : words){
            st.insert(word);
            int size=word.size();
            minLen=min(minLen,size);
        }
        for(auto word : words) {
            if(checkConcatenate(word,st,minLen,tempCache))
                concatenateWords.push_back(word);
        }
        return concatenateWords;
    }
};