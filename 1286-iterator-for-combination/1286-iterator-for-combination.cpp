class CombinationIterator {
private:
    vector<string> ans;
    int ptr=0;
    void backtrack(string s,int ind,int n, int len, string res){
        
        if(len==0){
            ans.push_back(res);
            return;
        }
        if(ind>=n) return;
        
        //take
        res+=s[ind];
        backtrack(s,ind+1,n,len-1,res);
        //backtrack and call for next 
        res.pop_back();
        backtrack(s,ind+1,n,len,res);
    }
public:
    CombinationIterator(string characters, int combinationLength) {
        string res="";
        backtrack(characters,0,characters.size(),combinationLength,res);
        ptr=0;
    }
    
    string next() {
        return ans[ptr++];
        
    }
    
    bool hasNext() {
        return ptr<ans.size();
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */