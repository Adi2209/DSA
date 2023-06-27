class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n=nums.size();
        
        for(int ind=0;ind<n;ind++){
            int ele=nums[ind];
            while(ele>=1 && ele<=n && nums[ele-1]!=ele) 
                swap(nums[ele-1],ele);
        }
        for(int ind=0;ind<n;ind++){
            if(ind+1!=nums[ind]) return ind+1;
        }
        return n+1;
    }
};