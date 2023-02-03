class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int n=arr.size(),currMax=-1;
        vector<int> ans(n,0);
        for(int ind=n-1;ind>=0;ind--){
            ans[ind]=currMax;
            if(currMax<arr[ind]) currMax=arr[ind];
        }
        return ans;
    }
};