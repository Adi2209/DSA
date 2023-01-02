class Solution {
public:
    bool detectCapitalUse(string word) {
        int n = word.size();
        int cntUpper = 0;
        
        for(int i=0;i<n;i++)
            if(word[i]>='A' && word[i]<='Z')
                cntUpper++;
        
        if(cntUpper==n || cntUpper==0 || (word[0]>='A' && word[0]<='Z' && cntUpper==1))
            return true;
        
        return false;
    }
};