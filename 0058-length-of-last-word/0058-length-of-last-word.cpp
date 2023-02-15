class Solution {
public:
    int lengthOfLastWord(string s) {
        int len=0;
        int ind=s.size()-1;
        while(ind >=0 && s[ind]==' ') ind--;
        while(ind>=0 && s[ind]!=' '){
            len++;
            ind--;
        }
        return len;
    }
};