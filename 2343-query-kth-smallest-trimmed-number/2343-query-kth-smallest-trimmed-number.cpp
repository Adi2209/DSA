class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        vector<int> ans(queries.size());
        int ansIdx=0,n=nums.size();
        for(auto &it:queries){
            int k=it[0];
            int subSize=it[1];
            priority_queue<pair<string,int>> pq;
            for(int ind=0;ind<n;ind++){
                
                string subStr=nums[ind].substr(nums[ind].size()-subSize,subSize);
                
                if(pq.size()<k)
                    pq.push({subStr,ind});
                else{
                    if(pq.top().first>subStr){
                        pq.pop();
                        pq.push({subStr,ind});
                    }
                }
            }
            ans[ansIdx]=pq.top().second;
            ansIdx++;
        }
        return ans;
    }
};