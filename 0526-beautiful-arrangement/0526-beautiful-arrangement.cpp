class Solution {
private:
    void countBeautiful(int ind,vector<int>& nums,int& cntBeauty,int n){
        if(ind>=n){
            cntBeauty++;
            return;
        }
        
        for(int i=ind;i<n;i++){
            if(nums[i]%(ind+1)==0 || (ind+1)% nums[i]==0){
                swap(nums[i],nums[ind]);
                countBeautiful(ind+1,nums,cntBeauty,n);
                //swapping again beacuse we need to see other combinations also
                swap(nums[i],nums[ind]);
            }
        }
    }
public:
    int countArrangement(int n) {
        
        vector<int> nums;
        for(int ind=1;ind<=n;ind++){
            nums.push_back(ind);
        }
        int cntBeauty=0;
        countBeautiful(0,nums,cntBeauty,nums.size());
        return cntBeauty;
    }
};