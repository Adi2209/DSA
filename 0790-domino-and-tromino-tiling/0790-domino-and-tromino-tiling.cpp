class Solution {
public:
    int numTilings(int n) {
        
        long long one=1, two=2, three=5, total;
        
        if (n==1)
            return one;
        if (n==2)
            return two;
        if (n==3)
            return three;
        
        for(int i=4; i<=n; i++){
            total = (2*three + one)%1000000007;
            one = two;
            two = three;
            three = total;
        }
        
        return total%1000000007;
    }
};