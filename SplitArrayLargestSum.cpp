class Solution {
    int isPossible(vector<int>& nums, int mid){
        int tempSum=0;
        int cnt=1,n=nums.size();
        
        for(int i=0;i<n;i++){
            if(tempSum+nums[i]<=mid){
                tempSum+=nums[i];
            }
            else{
                cnt++;
                tempSum=nums[i];
            }
        }
        return cnt;
    }
public:
    int splitArray(vector<int>& nums, int m) {
        int n=nums.size();
        int l=INT_MIN;
        int r=0;
        for(int i=0;i<n;i++){
            l=max(l,nums[i]);
            r+=nums[i];
        }
        int ans=0;
        while(l<=r){
            int mid=l+(r-l)/2;
            int cnt=isPossible(nums,mid);//no. of subarrays possible if max sum is mid
            
            if(cnt<=m){
                r=mid-1;
                ans=mid;
            }
            else{
                l=mid+1;
            }
        }
        return ans;
    }
};