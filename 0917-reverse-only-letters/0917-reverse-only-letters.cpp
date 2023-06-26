class Solution {
public:
    string reverseOnlyLetters(string s) {
        int n=s.size();
        int l=0,r=n-1;
        while(l<r){
            while( l<r && !(isalpha(s[l]))) l++;
            while( l<r && !(isalpha(s[r]))) r--;
            swap(s[l++],s[r--]);
        }
        return s;
    }
};