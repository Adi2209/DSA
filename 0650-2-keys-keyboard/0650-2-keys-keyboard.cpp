class Solution {
public:
    int minSteps(int n) {
        if(n==1) return 0;
        int divisor=2;
        while (n%divisor!=0) divisor++;
        return divisor+minSteps(n/divisor);
    }
};