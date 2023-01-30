class Solution {
private:
    void getMaxLen(int ind,int currLen,vector<int>& nums,int &maxLen,vector<int>& vis){
        //base case if already visited
        if(vis[ind]){
            maxLen=max(maxLen,currLen);
            return;
        }
        //solving one case
        vis[ind]=1;
        getMaxLen(nums[ind],currLen+1,nums,maxLen,vis);
    }
public:
    int arrayNesting(vector<int>& nums) {
        int n=nums.size();
        vector<int> vis(1e5+1,0);
        int maxLen=-1e9;
        for(int ind=0;ind<n;ind++){
            if(!vis[ind]){
                getMaxLen(ind,0,nums,maxLen,vis);
            }
        }
        return maxLen;
    }
};