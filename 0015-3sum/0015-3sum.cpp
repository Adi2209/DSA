class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        int n=nums.size();
        if(n<3) return ans;
        for(int ind=0;ind<n-2;ind++){
            if(ind==0 || (ind>0 && nums[ind]!=nums[ind-1])){
                int low=ind+1, high=n-1, sum=0-nums[ind];
                while(low<high){
                    int currSum=nums[low]+nums[high];
                    if(currSum==sum){
                        vector<int> res(3);
                        res[0]=nums[ind];
                        res[1]=nums[low];
                        res[2]=nums[high];
                        ans.push_back(res);
                        
                        while(low<high && nums[low]==nums[low+1]) low++;
                        while(low<high && nums[high]==nums[high-1]) high--;
                        
                        low++;
                        high--;
                    }
                    else if(currSum < sum) low++;
                    else high--;
                }
            }
        }
        return ans;
    }
};