class Solution {
public:
    int countHomogenous(string s) {
        int count=0;
        int mod=1e9+7;
        int left=0,right=0;
        for(int ind=0;ind<s.size();ind++){
            if(s[left]==s[right]) right++;
            else{
                left=right;
                right++;
            }
            count=(count+(right-left)%mod)%mod;
        }
        return count;
    }
};