class Solution {
public:
    double nthPersonGetsNthSeat(int n) {
        double ans=1;
        if(n>=2) ans=ans/2;
        return ans;
    }
};