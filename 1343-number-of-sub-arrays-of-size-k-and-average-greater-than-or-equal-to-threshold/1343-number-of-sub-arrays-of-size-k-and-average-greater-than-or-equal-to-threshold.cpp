class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int cnt=0,sum=0,n=arr.size();
        
        for(int ind=0;ind<k;ind++) sum+=arr[ind];
        int targetSum=threshold*k;
        
        if(sum>=targetSum) cnt++;
        for(int ind=k;ind<arr.size();ind++){
            sum+=arr[ind]-arr[ind-k];
            if(sum>=targetSum) cnt++;
        }
        return cnt;
    }
};