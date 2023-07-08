class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        if(k==1) return 0;
        vector<long long> twoSum; //sum for two consecutive elements
        for(int ind=1;ind<weights.size();ind++){
            twoSum.push_back(weights[ind-1]+weights[ind]);
        }
        sort(twoSum.begin(),twoSum.end());
        long long leftSum=0,rightSum=0;
        int n=twoSum.size();
        for(int ind=0;ind+1<k;ind++){
            leftSum+=twoSum[ind];
            rightSum+=twoSum[n-ind-1];
        }
        return rightSum-leftSum;
    }
};