class Solution {
private:
    bool isValid(int nRow,int nCol,int rowSize,int colSize){
        return nRow>=0  && nRow<rowSize && nCol>=0 && nCol<colSize;
    }
    void markIsland(int row,int col,vector<vector<char>>& grid,int rowSize,int colSize,vector<vector<char>> &vis){
        char island='1';
        vis[row][col]='2';
        
        vector<int> delRow={-1,0,1,0};
        vector<int> delCol={0,1,0,-1};
        
        for(int ind=0;ind<4;ind++){
            int nRow=row+delRow[ind];
            int nCol=col+delCol[ind];
            if(isValid(nRow,nCol,rowSize,colSize) && vis[nRow][nCol]==island){
                markIsland(nRow,nCol,grid,rowSize,colSize,vis);
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int rowSize=grid.size(),colSize=grid[0].size();
        int islandCnt=0;
        vector<vector<char>> vis(rowSize,vector<char>(colSize));
        vis=grid;
        //for marking purpose
        char island='1';
        for(int row=0;row<rowSize;row++){
            for(int col=0;col<colSize;col++){
                if(vis[row][col]==island){
                    markIsland(row,col,grid,rowSize,colSize,vis);
                    islandCnt++;
                }
            }
        }
        return islandCnt;
    }
};