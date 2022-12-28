class Solution {
private:
    void bfs(int row,int col,vector<vector<int>>& vis,vector<vector<char>>& grid){
        vis[row][col]=1;
        queue<pair<int,int>> q;
        q.push({row,col});
        int n=grid.size();
        int m=grid[0].size();
        
        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            //now we will traverse in all the 8 directions 
            for(int delRow=-1;delRow<=1;delRow++){
                for(int delCol=-1;delCol<=1;delCol++){
                     if(delRow==-1&&delCol==0||delRow==0&&delCol==1
                        ||delRow==1&&delCol==0||delRow==0&&delCol==-1){
                        int nRow=row+delRow;
                        int nCol=col+delCol;
                        if(nRow>=0 && nRow<n && nCol>=0 && nCol<m && grid[nRow][nCol]=='1'
                          && !vis[nRow][nCol]){
                            vis[nRow][nCol]=1;
                            q.push({nRow,nCol});   
                        }
                    }
                }
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        int cnt=0;
        for(int row=0;row<n;row++){
            for(int col=0;col<m;col++){
                if(!vis[row][col] && grid[row][col]=='1'){
                    cnt++;
                    bfs(row,col,vis,grid);
                }
            }
        }
        return cnt;
    }
};