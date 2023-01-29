class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        priority_queue<pair<int,int>> pq;
        for(int i=0;i<nums.size();i++) pq.push({nums[i],i});

        vector<int> index;
        while(k--){
            pair<int,int> top=pq.top();
            index.push_back(top.second);
            pq.pop();
        }
        sort(index.begin(),index.end());

        vector<int> ans;
        for(int i=0;i<index.size();i++)
            ans.push_back(nums[index[i]]);

        return ans;
    }
};