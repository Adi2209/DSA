class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        unordered_map<int,int> freq;
        priority_queue<pair<int,int> > pq;
        
        for(auto &i:nums) freq[i]++;
        
        for(auto [frq,i]:freq) pq.push({i,frq});//here frq is value and i is key
        pair<int,int> curr;
        while(k>0 && !pq.empty()){
            curr=pq.top();
            pq.pop();
            ans.push_back(curr.second);
            k--;
        }
        return ans;
    }
};