class Solution {
private:
    bool isValid(int nRow,int nCol,int rowSize,int colSize){
        return nRow<rowSize && nRow>=0 && nCol<colSize && nCol>=0;
    }
    void markIsland(int row,int col,int rowSize,int colSize,vector<vector<int>>& vis,vector<vector<int>>& grid2,vector<vector<int>>& grid1,bool& flag){
        vis[row][col]=1;
        if(grid1[row][col]==0) flag=false;
        vector<int> delRow={-1,0,1,0};
        vector<int> delCol={0,1,0,-1};
        for(int ind=0;ind<4;ind++){
            int nRow=row+delRow[ind];
            int nCol=col+delCol[ind];
            if(isValid(nRow,nCol,rowSize,colSize) && vis[nRow][nCol]==0 && grid2[nRow][nCol]==1){
                markIsland(nRow,nCol,rowSize,colSize,vis,grid2,grid1,flag);
            }
        }
    }
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int rowSize=grid1.size();
        int colSize=grid1[0].size();
        vector<vector<int>> vis(rowSize,vector<int> (colSize,0));
        int islandCnt=0;
        bool flag=true;
        for(int row=0;row<rowSize;row++){
            for(int col=0;col<colSize;col++){
                flag=true;
                if(vis[row][col]==0 && grid2[row][col]==1){
                    markIsland(row,col,rowSize,colSize,vis,grid2,grid1,flag);
                    if(flag) islandCnt++;
                }
            }
        }
        return islandCnt;
    }
};