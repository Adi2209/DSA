class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int rowSize=grid.size();
        int colSize=grid[0].size();
        map<vector<int>,int> mp;
        for(vector<int> it:grid){
            mp[it]++;
        }
        int cnt=0;
        for(int row=0;row<rowSize;row++){
            vector<int> column;
            for(int col=0;col<colSize;col++){
                column.push_back(grid[col][row]);
                if(mp.find(column)!=mp.end()) cnt+=mp[column];
            }
        }
        return cnt;
    }
};