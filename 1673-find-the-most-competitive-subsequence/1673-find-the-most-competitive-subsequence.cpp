class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        int n=nums.size();
        int numsToDel=n-k;
        stack<int> st;
        for(int ind=0;ind<n;ind++){
            while(!st.empty() && nums[ind]<st.top() && numsToDel){
                st.pop();
                numsToDel--;
            }
            st.push(nums[ind]);
        }
        vector<int> ans;
        while(!st.empty()){
            int top=st.top();
            ans.push_back(top);
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        vector<int>ans2;
        for(int i=0; i<k; i++) {
            ans2.push_back(ans[i]);
        }
        return ans2;
    }
};