class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double maxAvg=INT_MIN;
        double sum=0;
        for(int ind=0;ind<k;ind++){
            sum+=nums[ind];
        }
        maxAvg=max(maxAvg,sum/k);
        for(int ind=k;ind<nums.size();ind++){
            sum+=nums[ind]-nums[ind-k];
            maxAvg=max(maxAvg,sum/k);
        }
        return maxAvg;
    }
};