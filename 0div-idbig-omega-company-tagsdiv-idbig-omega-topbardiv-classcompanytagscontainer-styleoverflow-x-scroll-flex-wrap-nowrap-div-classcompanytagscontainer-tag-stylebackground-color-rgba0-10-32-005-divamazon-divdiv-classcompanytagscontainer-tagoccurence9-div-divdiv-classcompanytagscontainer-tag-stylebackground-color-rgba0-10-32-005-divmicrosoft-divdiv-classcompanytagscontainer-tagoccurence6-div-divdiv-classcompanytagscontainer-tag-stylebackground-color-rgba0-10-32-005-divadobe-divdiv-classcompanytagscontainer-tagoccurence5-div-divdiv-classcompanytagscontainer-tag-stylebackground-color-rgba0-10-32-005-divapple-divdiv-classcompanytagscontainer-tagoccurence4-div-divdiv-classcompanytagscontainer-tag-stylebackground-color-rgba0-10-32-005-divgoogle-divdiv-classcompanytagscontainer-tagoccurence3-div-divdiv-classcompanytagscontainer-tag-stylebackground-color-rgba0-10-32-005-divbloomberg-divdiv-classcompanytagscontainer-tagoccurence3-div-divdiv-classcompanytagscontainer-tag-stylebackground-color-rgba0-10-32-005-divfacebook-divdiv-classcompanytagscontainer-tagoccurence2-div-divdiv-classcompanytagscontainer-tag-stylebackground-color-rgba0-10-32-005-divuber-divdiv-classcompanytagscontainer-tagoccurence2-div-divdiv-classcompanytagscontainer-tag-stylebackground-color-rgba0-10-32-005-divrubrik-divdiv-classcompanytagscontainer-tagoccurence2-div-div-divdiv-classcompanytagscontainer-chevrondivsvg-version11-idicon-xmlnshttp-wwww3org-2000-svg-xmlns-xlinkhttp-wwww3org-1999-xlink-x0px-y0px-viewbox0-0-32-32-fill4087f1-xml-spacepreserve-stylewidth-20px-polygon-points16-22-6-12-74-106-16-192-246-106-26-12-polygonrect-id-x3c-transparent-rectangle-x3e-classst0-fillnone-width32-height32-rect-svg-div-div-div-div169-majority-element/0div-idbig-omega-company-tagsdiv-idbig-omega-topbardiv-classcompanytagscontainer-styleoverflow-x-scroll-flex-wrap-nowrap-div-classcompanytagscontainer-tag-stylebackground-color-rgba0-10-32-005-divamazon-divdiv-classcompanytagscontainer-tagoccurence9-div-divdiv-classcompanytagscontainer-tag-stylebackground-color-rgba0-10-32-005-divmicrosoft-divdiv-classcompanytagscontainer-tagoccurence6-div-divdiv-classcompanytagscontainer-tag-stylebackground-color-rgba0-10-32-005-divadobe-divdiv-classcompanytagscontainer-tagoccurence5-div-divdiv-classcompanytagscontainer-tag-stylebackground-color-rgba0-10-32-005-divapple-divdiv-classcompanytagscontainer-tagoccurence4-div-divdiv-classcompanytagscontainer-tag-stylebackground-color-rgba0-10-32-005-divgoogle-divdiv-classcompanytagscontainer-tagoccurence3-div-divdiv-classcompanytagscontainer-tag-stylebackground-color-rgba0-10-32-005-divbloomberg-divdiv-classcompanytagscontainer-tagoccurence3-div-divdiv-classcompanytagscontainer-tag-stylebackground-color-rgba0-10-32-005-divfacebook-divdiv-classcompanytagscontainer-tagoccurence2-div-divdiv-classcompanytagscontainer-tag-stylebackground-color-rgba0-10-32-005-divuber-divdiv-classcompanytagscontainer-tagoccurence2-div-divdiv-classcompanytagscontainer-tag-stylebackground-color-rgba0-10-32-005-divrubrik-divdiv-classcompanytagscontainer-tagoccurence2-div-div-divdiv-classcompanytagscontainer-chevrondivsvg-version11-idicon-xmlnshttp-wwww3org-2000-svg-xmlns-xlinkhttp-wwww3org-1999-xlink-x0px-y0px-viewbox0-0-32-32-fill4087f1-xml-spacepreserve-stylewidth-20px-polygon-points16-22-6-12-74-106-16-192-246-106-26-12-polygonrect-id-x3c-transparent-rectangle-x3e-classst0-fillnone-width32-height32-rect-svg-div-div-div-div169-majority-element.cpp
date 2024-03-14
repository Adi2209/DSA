class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int size = nums.size();
        int cnt=0, ans=0;
        for(int ind= 0 ;ind<size;ind++){
            if(ans == nums[ind]){
                cnt++;
            }
            else if(cnt == 0){
                cnt=1;
                ans=nums[ind];
            }
            else cnt--;
        }
        return ans;
        
    }
};