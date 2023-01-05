class Solution {
private:
    bool isValid(int nRow,int nCol,int n){
        return nRow>= 0 && nRow<n && nCol>=0 && nCol<n;
    }
    void dfs(int row,int col, vector<vector<int>>& grid,vector<pair<int,int>>& island,
            vector<vector<int>> &vis,vector<int>& delRow,vector<int>& delCol){
        int n=grid.size();
        grid[row][col]=0;
        // vis[row][col]=1;
        island.push_back({row,col});
        for(int i=0;i<4;i++){
            int nRow=row+delRow[i];
            int nCol=col+delCol[i];
            if(isValid(nRow,nCol,n) && grid[nRow][nCol]==1){
                dfs(nRow,nCol,grid,island,vis,delRow,delCol);
            }
        }
    }
public:   
    int shortestBridge(vector<vector<int>>& grid) {
        //find all the coordinates of both the islands;
        int n=grid.size();
        vector<pair<int,int>> island1;
        vector<pair<int,int>> island2;
        vector<vector<int>> vis(n,vector<int>(n,0));
        int islandCnt=0;
        for(int row=0;row<n;row++){
            for(int col=0;col<n;col++){
                vector<int> delRow{-1,0,1,0};
                vector<int> delCol{0,1,0,-1};
                if(grid[row][col]==1){
                    islandCnt++;
                    if(islandCnt==1){
                        dfs(row,col,grid,island1,vis,delRow,delCol);
                    }
                    else if(islandCnt==2){
                        vis.clear();
                        dfs(row,col,grid,island2,vis,delRow,delCol);
                    }
                }
            }
        }
        int minDist=INT_MAX;
        for(int i=0;i<island1.size();i++){
            for(int j=0;j<island2.size();j++){
                int x1=island1[i].first;
                int x2=island2[j].first;
                int y1=island1[i].second;
                int y2=island2[j].second;
                
                int dist=abs(x1-x2)+abs(y1-y2)-1;
                minDist=min(minDist,dist);
            }
        }
        return minDist;
    }
};