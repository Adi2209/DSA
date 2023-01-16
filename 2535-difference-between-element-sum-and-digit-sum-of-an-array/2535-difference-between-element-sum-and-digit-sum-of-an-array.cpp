class Solution {
private:
    
    int getDigitSum(int num){
        int sum=0;
        while(num){
            int digit=num%10;
            sum+=digit;
            num/=10;
        }
        return sum;
    }
    void getSums(int n,int& digitSum,int& total,vector<int>& nums){
        
        for(int ind=0;ind<n;ind++){
            int element=nums[ind];
            total+=element;
            int tempSum=getDigitSum(element);
            digitSum+=tempSum;
            
        }
    }
public:
    int differenceOfSum(vector<int>& nums) {
        int n=nums.size();
        int digitSum=0,total=0;
        getSums(n,digitSum,total,nums);
        
        int ans=abs(digitSum-total);
        return ans;
    }
};