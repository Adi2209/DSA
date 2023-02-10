class Solution {
private:
    bool isValid(int nRow,int nCol,int row,int col){
        return nRow>=0 && nRow<row && nCol>=0 && nCol<col;
    }
public:
    int maxDistance(vector<vector<int>>& grid) {
        int rowSize=grid.size();
        int colSize=grid[0].size();
        queue<pair<int,int>> q;
        // {row,col}
        for(int i=0;i<rowSize;i++){
            for(int j=0;j<colSize;j++){
                if(grid[i][j]==1){
                    q.push({i,j});
                }
            }
        }
        vector<vector<int> > vis=grid;
        int distance=-1e9;
        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            vector<int> delRow{0,-1,0,1};
            vector<int> delCol{1,0,-1,0};
            for(int ind=0;ind<4;ind++){
                int nRow=row+delRow[ind];
                int nCol=col+delCol[ind];
                if(isValid(nRow,nCol,rowSize,colSize) && vis[nRow][nCol]==0){
                    q.push({nRow,nCol});
                    vis[nRow][nCol]=vis[row][col]+1;
                    distance=max(distance,vis[nRow][nCol]);
                }
            }
        }
        return distance>0 ? distance-1:-1;//+1 because we are intialising with -1
    }
};