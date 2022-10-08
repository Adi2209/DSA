class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        
         int n=nums.size();
        sort(nums.begin(),nums.end());
        
        int closestsum=nums[0]+nums[1]+nums[n-1];
        
        for(int i=0;i<n;i++){
            
            int s=i+1;
            int e=n-1;
            
            while(s<e){
                int currsum=nums[i]+nums[s]+nums[e];
                
                if(currsum>target){
                    e--;
                }
                else{
                    s++;
                }
                
                if(abs(currsum-target)<abs(closestsum-target)){
                    closestsum=currsum;
                }
            }
        }
        return closestsum;
    }
};
