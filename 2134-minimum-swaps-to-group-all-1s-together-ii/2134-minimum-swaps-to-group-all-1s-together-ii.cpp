class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n=nums.size(),cntOne=0;
        
        for(auto &it:nums){
            if(it==1) cntOne++;
        }
        
        int window=cntOne;
        int maxOnes=0,cnt=0;
        for(int i=0;i<window;i++){
            if(nums[i]==1) cnt++;
        }
        maxOnes = cnt;
        for(int i=window;i<n+window;i++){
            if(nums[i-window]==1) cnt--;
            if(nums[i%n]==1) cnt++; 
            maxOnes = max(maxOnes,cnt);
        }
        return(window - maxOnes); 
    }
};