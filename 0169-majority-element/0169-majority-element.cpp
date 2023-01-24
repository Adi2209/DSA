class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        int cnt=0;
        int ele=nums[0];
        for(int ind=0;ind<n;ind++){
            if(ele==nums[ind]){
                cnt++;
            }
            else if(cnt==0 && ele!=nums[ind]){
                ele=nums[ind];
            }
            else
                cnt--;
        }
        return ele;
    }
};