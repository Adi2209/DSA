class Solution {
public:
    int numberOfSpecialChars(string word) {
        int cnt = 0;
        set<char> upper;
        set<char> lower;
        for(auto it:word){
            if(it>='a' && it<='z') lower.insert(it-'a');
            else if( it>='A' && it<='Z') upper.insert(it-'A');
        }
        
        for(auto it:lower){
            // cout<<it<<endl;
            cout<<it<<endl;
            if(upper.find(it)!=upper.end()) cnt++;
        }
        return cnt;
    }
};