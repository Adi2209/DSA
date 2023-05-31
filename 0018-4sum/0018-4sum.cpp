class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<vector<int>> ans;
        if(n<4) return ans;
        
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                
                long long newTarget=(long long)target-nums[i]-nums[j];
                int left=j+1, right=n-1;
                
                while(left<right){
                    long long twoSum=nums[left]+nums[right];
                    if(twoSum<newTarget) left++;
                    else if(twoSum>newTarget) right--;
                    else{
                        vector<int> res(4);
                        res[0]=nums[i];
                        res[1]=nums[j];
                        res[2]=nums[left];
                        res[3]=nums[right];
                        ans.push_back(res);
                        //skipping same elements
                        while(left<right && nums[left]==res[2]) left++;
                        while(left<right && nums[right]==res[3]) right--;
                    }
                }
                while(j+1<n && nums[j]==nums[j+1]) j++;
            }
            while(i+1<n && nums[i]==nums[i+1]) i++;
        }
        return ans;
    }
};