class Solution {
public:
    string convertToTitle(int n) {
        string ans;
        n--;
        while(n>=0){
            int d=n%26;
            ans+=('A'+d);
            n/=26;
            n--;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};