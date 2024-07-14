class Solution {
public:
    string getSmallestString(string s) {
        int size = s.size();
        
        for(int ind = 1;ind<size;ind++){
            if(s[ind]%2==0 && s[ind-1]%2==0 && s[ind-1]>s[ind]){
                swap(s[ind],s[ind-1]);
                return s;
            }
            if(s[ind]%2!=0 && s[ind-1]%2!=0 && s[ind-1]>s[ind]){
                swap(s[ind],s[ind-1]);
                return s;
            }

        }
        return s;
    }
};