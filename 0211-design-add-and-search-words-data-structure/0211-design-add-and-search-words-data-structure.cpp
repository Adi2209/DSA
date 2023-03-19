class WordDictionary {
private:
    bool check(string &a, string &b){
        int i = 0;
        while(i < a.size()){
            if(b[i] != '.' && b[i] != a[i]) return false;
            i++;
        }

        return true;
    }

public:
    unordered_map<int, vector<string>> mp;

    WordDictionary() {}
    
    void addWord(string word) {
        mp[word.size()].push_back(word);
    }
    
    bool search(string word) {
        if(mp.find(word.size()) == mp.end()) return false;

        for(auto &i : mp[word.size()]){
            bool ans = check(i, word);
            if(ans) return true;
        }

        return false;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */