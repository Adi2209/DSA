class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        // this can be solved using moore's voting algo with some modifications
        int n=nums.size();
        int ele1=0,ele2=0,cnt1=0,cnt2=0;
        
        for(int ind=0;ind<n;ind++){
            if(cnt1==0 && ele2!=nums[ind]){
                cnt1=1;
                ele1=nums[ind];
            }
            else if(cnt2==0 && ele1!=nums[ind]){
                cnt2=1;
                ele2=nums[ind];
            }
            else if(ele1==nums[ind]) cnt1++;
            else if(ele2==nums[ind]) cnt2++;
            else{
                cnt1--;
                cnt2--;
            }
        }
        cnt1=0,cnt2=0;
        for(auto &it:nums){
            if(it==ele1) cnt1++;
            else if(it==ele2) cnt2++;
        }
        vector<int> ans;
        int mini=(int)(n/3)+1;
        if(cnt1>=mini) ans.push_back(ele1);
        if(cnt2>=mini) ans.push_back(ele2);
        
        sort(ans.begin(),ans.end());
        return ans;
    }
};