class Solution {
public:
    int minFlipsMonoIncr(string s) {
        
        int flips=0,cntOne=0;
        
        for(auto &ch:s){
            if(ch=='1') cntOne++;
            else flips++;
            
            flips=min(cntOne,flips);
        }
        return flips;
    }
};