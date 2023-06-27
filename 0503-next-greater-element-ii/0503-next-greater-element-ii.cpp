class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(n,-1);
        stack<int> st;
        for(int ind=2*n-1;ind>=0;ind--){
            while(!st.empty() && st.top()<=nums[ind%n]) st.pop();
            if(ind<n){
                if(!st.empty()){
                    ans[ind]=st.top();
                }
                else{
                    ans[ind]=-1;
                }
            }
            st.push(nums[ind%n]);
        }
        return ans;
    }
};