class Solution {
private:
    bool isPalindrome(int left,int right,string s){
        while(left<right){
            if(s[left]!=s[right]){
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
    void solve(int idx,string s,vector<vector<string>>& ans,vector<string>& res){
        //base case
        if(idx>=s.size()){
            ans.push_back(res);
            return;
        }
        //if till now palindrome
        for(int i=idx;i<s.size();i++){
            if(isPalindrome(idx,i,s)){
                res.push_back(s.substr(idx,i-idx+1));
                //calling for the next iteration
                solve(i+1,s,ans,res);
                res.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string> > ans;
        vector<string> res;
        solve(0,s,ans,res);
        
        return ans;
    }
};