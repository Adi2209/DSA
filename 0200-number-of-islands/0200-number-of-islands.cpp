class Solution {
private:
    bool isValid(int nRow,int nCol,int rowSize,int colSize){
        return nRow<rowSize && nCol<colSize && nRow>=0 & nCol>=0;
    }
    void markIsland(int row,int col,vector<vector<char>>& vis,int rowSize,int colSize){
        vis[row][col]='2';
        char island='1';
        vector<int> delRow={-1,0,1,0};
        vector<int> delCol={0,1,0,-1};
        for(int ind=0;ind<4;ind++){
            int nRow=row+delRow[ind];
            int nCol=col+delCol[ind];
            if(isValid(nRow,nCol,rowSize,colSize) && vis[nRow][nCol]==island){
                markIsland(nRow,nCol,vis,rowSize,colSize);
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int rowSize=grid.size(),colSize=grid[0].size();
        vector<vector<char>>vis=grid;
        int islandCnt=0;
        char island='1';
        for(int row=0;row<rowSize;row++){
            for(int col=0;col<colSize;col++){
                if(vis[row][col]==island){
                    markIsland(row,col,vis,rowSize,colSize);
                    islandCnt++;
                }
            }
        }
        return islandCnt;
    }
};