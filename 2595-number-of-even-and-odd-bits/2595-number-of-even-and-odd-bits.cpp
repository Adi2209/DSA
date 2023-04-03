class Solution {
public:
    vector<int> evenOddBit(int n) {
        int oddSetBits=0,evenSetBits=0;
        int i=0;
        while(n>0){
            if(i%2==0){
                if(n%2==1) evenSetBits++;
            }
            else{
                if(n%2==1) oddSetBits++;
            }
            n=n/2;
            i++;
            
        }
        return {evenSetBits,oddSetBits};
    }
};