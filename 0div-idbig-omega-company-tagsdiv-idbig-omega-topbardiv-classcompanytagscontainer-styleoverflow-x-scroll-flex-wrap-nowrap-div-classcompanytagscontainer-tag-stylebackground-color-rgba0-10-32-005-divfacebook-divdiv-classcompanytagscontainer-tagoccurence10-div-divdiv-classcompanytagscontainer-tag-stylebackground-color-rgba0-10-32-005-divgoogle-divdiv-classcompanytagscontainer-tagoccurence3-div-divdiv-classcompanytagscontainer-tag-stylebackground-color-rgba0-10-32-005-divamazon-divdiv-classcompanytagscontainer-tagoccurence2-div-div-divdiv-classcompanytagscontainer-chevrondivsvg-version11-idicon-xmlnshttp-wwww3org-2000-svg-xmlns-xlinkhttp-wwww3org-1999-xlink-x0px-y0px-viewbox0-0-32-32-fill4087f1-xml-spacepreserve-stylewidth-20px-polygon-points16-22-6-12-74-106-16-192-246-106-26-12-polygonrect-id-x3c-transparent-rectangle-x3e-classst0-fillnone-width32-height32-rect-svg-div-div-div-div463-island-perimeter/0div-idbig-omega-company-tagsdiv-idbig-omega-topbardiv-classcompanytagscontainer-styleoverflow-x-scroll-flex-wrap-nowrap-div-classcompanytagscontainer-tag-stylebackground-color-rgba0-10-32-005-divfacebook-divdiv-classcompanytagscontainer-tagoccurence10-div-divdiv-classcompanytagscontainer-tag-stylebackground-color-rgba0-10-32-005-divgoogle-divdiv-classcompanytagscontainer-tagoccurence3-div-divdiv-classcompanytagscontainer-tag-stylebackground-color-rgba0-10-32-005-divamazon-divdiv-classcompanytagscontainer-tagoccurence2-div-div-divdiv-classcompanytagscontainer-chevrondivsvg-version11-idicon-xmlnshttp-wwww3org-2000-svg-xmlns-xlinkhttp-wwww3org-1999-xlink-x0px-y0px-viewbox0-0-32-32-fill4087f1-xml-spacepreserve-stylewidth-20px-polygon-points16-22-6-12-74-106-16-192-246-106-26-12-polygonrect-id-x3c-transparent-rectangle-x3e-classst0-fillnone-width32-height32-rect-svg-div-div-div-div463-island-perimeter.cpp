class Solution {
private:
    bool isValid(int row,int col, int rowSize, int colSize){
        return row>=0 && row<rowSize && col>=0 && col<colSize;
    }
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int rowSize = grid.size();
        int colSize = grid[0].size();
        int perimeter = 0;
        for(int row = 0;row<rowSize;row++){
            for(int col = 0;col<colSize;col++){
                if(grid[row][col]==1){
                    perimeter+=4;
                    vector<int> delRow{-1,0,1,0};
                    vector<int> delCol{0,1,0,-1};
                    for(int ind = 0;ind<4;ind++){
                        int deltaCol = col + delCol[ind];
                        int deltaRow = row + delRow[ind];
                        if(isValid(deltaRow,deltaCol,rowSize,colSize) && grid[deltaRow][deltaCol] == 1){
                            perimeter --;
                        }
                    }
                }
            }
        }
        return perimeter;
    }
};