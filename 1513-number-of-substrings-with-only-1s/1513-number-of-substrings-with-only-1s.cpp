class Solution {
public:
    int numSub(string s) {
        int count=0,total=0;
        int mod=1e9+7;
        for(auto ch:s){
            if(ch=='0') count=0;
            else count++;
            total=(total+count)%mod;
        }
        return total;
    }
};