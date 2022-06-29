class Solution {
    vector<string> res;
    void solve(int open,int close,int n,string ans){
        
        if(ans.size()==n*2){
            res.push_back(ans);
            return;
        }
        if(open<n) solve(open+1,close,n,ans+'(');
        if(close<open) solve(open,close+1,n,ans+')');             
}
public:
    vector<string> generateParenthesis(int n) {
        string ans;
        solve(0,0,n,"");
        return res;
        
    }
};