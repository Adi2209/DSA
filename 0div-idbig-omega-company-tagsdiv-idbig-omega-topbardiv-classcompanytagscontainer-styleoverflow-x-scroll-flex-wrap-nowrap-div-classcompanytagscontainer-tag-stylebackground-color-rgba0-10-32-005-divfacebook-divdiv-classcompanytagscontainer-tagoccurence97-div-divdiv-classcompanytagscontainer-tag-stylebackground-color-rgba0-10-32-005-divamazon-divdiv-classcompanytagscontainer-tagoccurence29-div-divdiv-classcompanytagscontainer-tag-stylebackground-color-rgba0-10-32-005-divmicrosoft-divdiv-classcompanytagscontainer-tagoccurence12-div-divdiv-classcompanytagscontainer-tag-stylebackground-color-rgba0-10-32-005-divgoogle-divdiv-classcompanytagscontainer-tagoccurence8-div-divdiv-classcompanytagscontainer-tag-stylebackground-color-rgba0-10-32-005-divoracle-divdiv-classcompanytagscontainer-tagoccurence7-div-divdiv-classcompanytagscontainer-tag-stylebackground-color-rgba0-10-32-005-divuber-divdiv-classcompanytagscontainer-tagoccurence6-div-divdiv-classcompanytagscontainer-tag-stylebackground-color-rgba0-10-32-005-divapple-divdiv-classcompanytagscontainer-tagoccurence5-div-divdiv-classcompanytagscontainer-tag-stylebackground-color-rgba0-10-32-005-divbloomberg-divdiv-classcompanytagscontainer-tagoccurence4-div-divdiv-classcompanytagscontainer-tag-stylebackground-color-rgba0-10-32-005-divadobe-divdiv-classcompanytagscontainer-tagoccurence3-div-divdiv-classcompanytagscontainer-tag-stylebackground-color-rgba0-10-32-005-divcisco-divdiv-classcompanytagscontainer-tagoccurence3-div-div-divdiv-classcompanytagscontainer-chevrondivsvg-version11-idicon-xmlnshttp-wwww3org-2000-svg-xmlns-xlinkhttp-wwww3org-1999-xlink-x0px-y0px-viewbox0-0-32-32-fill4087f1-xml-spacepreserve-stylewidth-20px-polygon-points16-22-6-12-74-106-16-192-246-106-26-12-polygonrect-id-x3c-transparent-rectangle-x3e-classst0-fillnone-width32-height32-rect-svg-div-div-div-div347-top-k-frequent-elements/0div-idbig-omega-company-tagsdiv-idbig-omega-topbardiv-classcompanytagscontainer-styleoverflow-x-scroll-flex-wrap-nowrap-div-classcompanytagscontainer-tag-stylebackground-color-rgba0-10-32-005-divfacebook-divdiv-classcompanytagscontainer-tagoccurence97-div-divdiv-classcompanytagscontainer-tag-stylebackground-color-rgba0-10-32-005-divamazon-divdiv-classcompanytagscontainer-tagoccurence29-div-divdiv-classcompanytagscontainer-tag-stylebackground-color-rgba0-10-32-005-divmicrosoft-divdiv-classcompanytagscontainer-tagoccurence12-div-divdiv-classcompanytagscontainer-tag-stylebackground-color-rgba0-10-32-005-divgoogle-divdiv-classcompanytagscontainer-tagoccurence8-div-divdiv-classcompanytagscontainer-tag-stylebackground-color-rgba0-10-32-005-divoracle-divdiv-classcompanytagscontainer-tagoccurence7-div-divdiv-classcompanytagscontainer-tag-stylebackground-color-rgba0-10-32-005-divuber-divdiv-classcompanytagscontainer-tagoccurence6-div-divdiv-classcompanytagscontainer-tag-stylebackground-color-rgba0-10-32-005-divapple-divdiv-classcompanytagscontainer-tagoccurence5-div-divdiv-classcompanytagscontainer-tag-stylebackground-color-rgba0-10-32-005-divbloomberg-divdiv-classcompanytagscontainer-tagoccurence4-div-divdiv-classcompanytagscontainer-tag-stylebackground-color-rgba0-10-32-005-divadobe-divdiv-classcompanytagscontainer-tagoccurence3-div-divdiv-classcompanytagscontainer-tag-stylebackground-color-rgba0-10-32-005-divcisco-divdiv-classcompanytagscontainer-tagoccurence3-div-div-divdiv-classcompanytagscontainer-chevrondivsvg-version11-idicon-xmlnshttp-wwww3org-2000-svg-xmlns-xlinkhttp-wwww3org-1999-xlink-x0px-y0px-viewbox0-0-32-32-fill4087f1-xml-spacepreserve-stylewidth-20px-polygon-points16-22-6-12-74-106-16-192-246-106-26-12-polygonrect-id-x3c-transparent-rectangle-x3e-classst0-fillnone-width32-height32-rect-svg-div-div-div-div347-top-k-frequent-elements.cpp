class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        unordered_map<int,int> freqMap;
        
        for(auto &it:nums){
            freqMap[it]++;
        }
        int n= nums.size();
        
        vector<vector<int>> buckets(n+1);
        
        for(auto it:freqMap){
            buckets[it.second].push_back(it.first);
        }
        
        for(int ind=n;ind>=0;ind--){
            if (ans.size() >= k) {
                break;
            }
            if(!buckets[ind].empty()){
                ans.insert(ans.end(),buckets[ind].begin(),buckets[ind].end());
            }

        }
        return ans;
    }
};