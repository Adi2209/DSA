class Solution {
private:
    vector<int> getVector(int n){
        vector<int> nums;
        while(n){
            int digit=n%10;
            nums.push_back(digit);
            n/=10;
        }
        reverse(nums.begin(),nums.end());
        return nums;
    }
    int convertToInt(vector<int>& nums){
        int ans = 0;
        for(int ind=0;ind<nums.size();ind++){
            ans=ans*10+nums[ind];
        }
            
        return ans;
    }
public:
    int monotoneIncreasingDigits(int n) {
        //get n in terns of array to traverse
        vector<int> nums=getVector(n);
        int changeIdx=-1;
        for(int ind=nums.size()-1;ind>0;ind--){
            if(nums[ind-1]>nums[ind]){
                changeIdx=ind;
                nums[ind-1]--;
            }
        }
        for(int ind=changeIdx;ind<nums.size();ind++){
            nums[ind]=9;
        }
        //converting again to int
        int ans=convertToInt(nums);
        return ans;
    }
};