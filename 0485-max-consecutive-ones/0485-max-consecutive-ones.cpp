class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n=nums.size();
        int cnt=0,maxOnes=INT_MIN;
        for(int ind=0;ind<n;ind++){
            if(nums[ind]==1) cnt++;
            else if(nums[ind]!=1){
                cnt=0;
            }
            maxOnes=max(maxOnes,cnt);
        }
        return maxOnes;
    }
};