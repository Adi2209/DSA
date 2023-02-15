class Solution {
private:
    bool isValid(int nRow,int nCol,int rowSize,int colSize){
        return nRow>=0 && nRow<rowSize && nCol>=0 && nCol<colSize;
    }
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        // perimeter= perimeter of total cells - cells with neighbours (as they will have common edges)
        int rowSize=grid.size(),colSize=grid[0].size();
        int perimeter=0;
        for(int row=0;row<rowSize;row++){
            for(int col=0;col<colSize;col++){
                //checking if the cell is land or not
                if(grid[row][col]==1){
                    perimeter+=4;
                    vector<int> delRow{-1,0,1,0};
                    vector<int> delCol{0,1,0,-1};
                    for(int ind=0;ind<4;ind++){
                        int nRow=row+delRow[ind];
                        int nCol=col+delCol[ind];
                        if(isValid(nRow,nCol,rowSize,colSize) && grid[nRow][nCol]==1){
                            perimeter--;
                        }
                    }
                }
            }
        }
        return perimeter;
    }
};