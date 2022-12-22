class Solution {
private:
    long long getSumOfFactors(int n){
        int divisor=2;
        long long ans=0;
        
        while(n>1){
            if(n%divisor==0){
                ans+=divisor;
                n/=divisor;
            }
            else
                divisor++;
        }
        return ans;
    }
public:
    int smallestValue(int n) {
        
        while(true){
            long long sumOfFactors=getSumOfFactors(n);
            if(n==sumOfFactors) break;
            n=sumOfFactors;
        }
        return n;
    }
};