class NumArray {
public:
    vector<int> res;
    int sum=0;
    NumArray(vector<int>& nums) {
        res=nums;
        sum=0;
        for(auto i:nums) sum+=i;
        
    }
    void update(int index, int val) {
        //subtracting the old value and adding the new value to the sum
        sum-=res[index];
        res[index]=val;
        sum+=val;
    }
    
    int sumRange(int left, int right) {
        int ans=sum;
        //finding the usm between left and right
        for(int i=0;i<left;i++){
            ans-=res[i];
        }
        for(int i=right+1;i<res.size();i++){
            ans-=res[i];
        }
        return ans;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
