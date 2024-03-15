class Solution {
private:
    int traverseDFS(int row, int col, vector<vector<int>>& visited,int rowSize,int colSize){
        
        if(row>=0 && col<colSize && col>=0 && row<rowSize && visited[row][col]){
            visited[row][col]= 0;
            return 1+traverseDFS(row+1,col,visited,rowSize,colSize)+traverseDFS(row-1,col,visited,rowSize,colSize)+
                traverseDFS(row,col+1,visited,rowSize,colSize)+traverseDFS(row,col-1,visited,rowSize,colSize);
        }
        return 0;
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        vector<vector<int>> visited = grid;
        int rowSize = grid.size();
        int colSize = grid[0].size();
        int maxArea = 0;
        for(int row = 0; row<rowSize;row++){
            for(int col = 0; col<colSize;col++){
                if(visited[row][col]==1){
                    int area = traverseDFS(row,col,visited,rowSize,colSize);
                    maxArea = max(area,maxArea);
                }
            }
        }
        return maxArea;
    }
};