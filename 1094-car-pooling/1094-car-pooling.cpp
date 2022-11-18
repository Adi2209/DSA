class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<pair<int,int>> res;
        
        for(int i=0;i<trips.size();i++){
            res.push_back({trips[i][1],trips[i][0]});
            res.push_back({trips[i][2],-trips[i][0]});
        }
        
        sort(res.begin(),res.end());
        int ans=0;
        for(int i=0;i<res.size();i++){
            ans+=res[i].second;
            if(ans>capacity)
                return false;
        }
        return true;
    }
};