class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n=nums.size();
        
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        if(n<4) return ans;
        
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int target_2=target-nums[i]-nums[j];
                int front=j+1,back=n-1;
                
                while(front<back){
                    int twoSum=nums[front]+nums[back];
                    
                    if(twoSum<target_2) front++;
                    else if(twoSum>target_2) back--;
                    else{
                        vector<int> quad(4);
                        quad[0]=nums[i];
                        quad[1]=nums[j];
                        quad[2]=nums[front];
                        quad[3]=nums[back];
                        ans.push_back(quad);
                        
                        //to skip repeating elements
                        while(front<back && nums[front]==quad[2]) front++;
                        while(front<back && nums[back]==quad[3]) back--;
                    }
                }
                 while(j+1<n && nums[j+1]==nums[j]) j++;
            }
            
            while(i+1<n && nums[i+1]==nums[i]) i++;
        }
        
        return ans;
    }
};