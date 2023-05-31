class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int majority=0,cnt=0;
        int n=nums.size();
        for(int ind=0;ind<n;ind++){
            if(majority==nums[ind]) cnt++;
            else if(cnt==0){
                cnt=1;
                majority=nums[ind];
            }
            else{
                cnt--;
            }
        }
        return majority;
    }
};