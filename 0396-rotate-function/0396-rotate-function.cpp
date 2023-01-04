class Solution {
private:
    int getTotalSumAndfuncSum(vector<int> &nums,int &n,int &originalSum){
        int sum=0;
        for(int ind=0;ind<n;ind++){
            sum+=nums[ind];
            originalSum+=(ind * nums[ind]);
        }
        return sum;
    }
public:
    int maxRotateFunction(vector<int>& nums) {
        int n=nums.size();
        int originalSum=0;
        int totalSum=getTotalSumAndfuncSum(nums,n,originalSum);
        
        int right=n-1;
        int maxi=originalSum;
        
        for(int ind=n-1;ind>=0;ind--){
            originalSum+=totalSum - (nums[ind]*n);
            maxi=max(originalSum,maxi);
        }
        return maxi;
    }
};