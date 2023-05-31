class Solution {
public:
    double myPow(double x, int n) {
        double ans=1.0;
        long long exp=n;
        if(n<0) exp*=-1;
        while(exp){
            //odd
            if(exp%2==1){
                ans*=x;
                exp-=1;
            }
            else{
                //even
                x*=x;
                exp/=2;
            }
        }
        cout<<"ans: "<<ans<<endl;
        if(n<0){
            ans=(double) 1.0/(double) ans;
        }
        return ans;
    }
};