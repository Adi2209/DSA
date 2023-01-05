class Solution {
public:
    int numberOfSubstrings(string s) {
        int left=0,right=0, end=s.size()-1;
        
        unordered_map<char,int> mp;
        int cnt=0;
        while(right<s.size()){
            mp[s[right]]++;
            while( mp['a'] && mp['b'] && mp['c']){
                cnt+=1+(end-right);
                //shrinking the window
                mp[s[left]]--;
                left++;
            }
            right++;
        }
        return cnt;
    }
};