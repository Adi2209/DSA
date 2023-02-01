class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        if(str1+str2 != str2+str1) return "";
        int size1=str1.size(),size2=str2.size();
        return str1.substr(0,__gcd(size1,size2));
    }
};