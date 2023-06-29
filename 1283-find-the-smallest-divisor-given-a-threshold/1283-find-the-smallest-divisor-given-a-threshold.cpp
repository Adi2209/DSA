class Solution {
private:
    bool isPossible(int div,vector<int>& nums,int threshold){
        int sum=0;
        for(auto it:nums){
            if(it%div==0) sum+=it/div;
            else{
                int res=it/div+1;
                sum+=res;
            }
        }
        return sum<=threshold;
    }
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n=nums.size();
        int low=1;
        int high=-1;
        for(auto it:nums) high=max(high,it);
        int ans=1e9;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(isPossible(mid,nums,threshold)){
                ans=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        return ans;
    }
};