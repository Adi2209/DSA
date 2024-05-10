class Solution {
private:
    int getSum(int num){
        int n = num;
        int sum = 0;
        while(n){
            int digit = n%10;
            sum+=digit;
            n/=10;
        }
        return sum;
    }
public:
    int sumOfTheDigitsOfHarshadNumber(int x) {
        int sum  = getSum(x);
        if(x%sum == 0) return sum;
        else return -1;
    }
};