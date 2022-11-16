class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int,int> mp;//this will store the losers
        set<int> st;//this will store the number of all players
        
        for(auto idx:matches){
            mp[idx[1]]++;
            
            st.insert(idx[0]);
            st.insert(idx[1]);
        }
        vector<vector<int>> ans(2);
        for(auto idx:st){
            if(mp.find(idx)==mp.end()){
                ans[0].push_back(idx);
            }
            else if(mp.find(idx)!=mp.end()){
                if(mp[idx]==1){
                    ans[1].push_back(idx);
                }
            }
        }
        return ans;
    }
};
