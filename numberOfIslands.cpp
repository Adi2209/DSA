class Solution {
private:
    void markIsland(vector<vector<char> >& matrix,int x,int y,int r,int c){
        
        if(x<0 || x>=r ||y<0 ||y>=c || matrix[x][y]!='1')
            return;
        //marking the current cell/island as visited
        matrix[x][y]='2';
        //recursive calls
        
        markIsland(matrix,x+1,y,r,c);
        markIsland(matrix,x,y+1,r,c);
        markIsland(matrix,x-1,y,r,c);
        markIsland(matrix,x,y-1,r,c);
        
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int row=grid.size();
        int col=grid[0].size();
        
        int islands=0;
        
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j]=='1'){
                    markIsland(grid,i,j,row,col);
                    islands++;
                }
            }
        }
        return islands;
    }
};