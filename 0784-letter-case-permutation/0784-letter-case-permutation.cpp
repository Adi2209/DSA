class Solution {
private:
    void solve(int ind, string& s,vector<string>& ans,string res){
        if(ind==s.size()){
            ans.push_back(res);
            return;
        }
        //if the char is lowercase
        if(s[ind]>='a' && s[ind]<='z'){
            char ch=s[ind]-32;
            res.push_back(ch);
            solve(ind+1,s,ans,res);
            res.pop_back();
            res.push_back(s[ind]);
            solve(ind+1,s,ans,res);
        }
        else if(s[ind]>='A' && s[ind]<='Z'){
            //if the char is uppercase
            char ch=s[ind]+32;
            res.push_back(ch);
            solve(ind+1,s,ans,res);
            res.pop_back();
            res.push_back(s[ind]);
            solve(ind+1,s,ans,res);
        }
        else if(s[ind]>='0' && s[ind]<='9'){
            res+=s[ind];
            solve(ind+1,s,ans,res);
            
        }
    }
public:
    vector<string> letterCasePermutation(string s) {
        vector<string> ans;
        string res;
        solve(0,s,ans,res);
        return ans;
    }
};