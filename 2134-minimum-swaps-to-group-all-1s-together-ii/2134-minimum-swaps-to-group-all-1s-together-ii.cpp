class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n=nums.size(),cntOne=0;
        
        for(auto &it:nums){
            if(it==1) cntOne++;
        }
        
        int window=cntOne;
        int maxOnes=0,cnt=0;
        for(int ind=0;ind<window;ind++){
            if(nums[ind]==1) cnt++;
        }
        maxOnes = cnt;
        for(int ind=window;ind<n+window;ind++){
            if(nums[ind-window]==1) cnt--;
            if(nums[ind%n]==1) cnt++; 
            maxOnes = max(maxOnes,cnt);
        }
        return(window - maxOnes); 
    }
};