class Solution {
public:
    int maxUniqueChar(string s) { 
        int count[26] = {0};
        for(int i = 0; i < s.size(); i++)
            if(count[s[i] - 'a']++ > 0) return 0;
        return s.size();
    }
    
    void solve(vector<string> &arr, int index, string curr, int &ans) {
        if(index == arr.size()) {            // BASE CONDITION
            if(maxUniqueChar(curr) > ans) {
            ans = curr.size();
            }
            return;
        }
        solve(arr, index+1, curr, ans); 
        solve(arr, index+1, curr+arr[index], ans);
    }
    
    int maxLength(vector<string> &arr) {
        int ans = 0;
        solve(arr, 0, "", ans);
        return ans;
    }
};
