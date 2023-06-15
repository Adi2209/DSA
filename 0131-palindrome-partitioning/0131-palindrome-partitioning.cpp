class Solution {
private:
    bool isPalindrome(string& str,int left,int right){
        while(left<=right){
            if(str[left]!=str[right]) return false;
            left++;
            right--;
        }
        return true;
    }
    void solve(int ind,vector<vector<string>>& ans,vector<string>& path, string& s,int n){
        //base case
        if(ind==n){
            ans.push_back(path);
            return;
        }
        // to traverse from index -> the string left
        for(int i=ind;i<n;i++){
            if(isPalindrome(s,ind,i)){
                path.push_back(s.substr(ind,i-ind+1));
                solve(i+1,ans,path,s,n);
                path.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        vector<string> path;
        vector<vector<string>> ans;
        int n=s.size();
        solve(0,ans,path,s,n);
        return ans;
    }
};