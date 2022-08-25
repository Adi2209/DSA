class Solution {
private:
    bool solveSO(vector<int>& nums,int n,int t){
        
        vector<int> curr(t+1,0);
        vector<int> next(t+1,0);
        
        curr[0]=1;
        next[0]=1;
                
        for(int idx=n-1;idx>=0;idx--){
            for(int target=0;target<=t/2;target++){
                bool include=0;
                if(target-nums[idx]>=0)
                    include=next[target-nums[idx]];
                bool exclude=next[target-0];

                curr[target]=include || exclude;
            }
            next=curr;
        }
        return next[t/2];
        
    }
public:
    bool canPartition(vector<int>& nums) {
        
        int n=nums.size();
        int total=0;
        for(int i=0;i<n;i++) total+=nums[i];
        
        if(total & 1)//if total is odd then it is impossible to divide it into two parts
            return false;
        
        int target=total;
    
        return solveSO(nums,n,target);
    }
};
