class Solution {
public:
    bool isPalindrome(int x) {
        
        long long temp=x;
        long long sum=0;
        if(x<0) return false;
        
        while(x!=0){
            int digit=x%10;
            sum=sum*10+digit;
            x/=10;
        }
        return temp==sum? true:false;
    }
};