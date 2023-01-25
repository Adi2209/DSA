class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        priority_queue<int,vector<int>,greater<int>> pq;
        for(auto it:nums) pq.push(it);
        vector<int> ans;
        while(!pq.empty()){
            int ele=pq.top();
            pq.pop();
            ans.push_back(ele);
        }
        return ans;
    }
};