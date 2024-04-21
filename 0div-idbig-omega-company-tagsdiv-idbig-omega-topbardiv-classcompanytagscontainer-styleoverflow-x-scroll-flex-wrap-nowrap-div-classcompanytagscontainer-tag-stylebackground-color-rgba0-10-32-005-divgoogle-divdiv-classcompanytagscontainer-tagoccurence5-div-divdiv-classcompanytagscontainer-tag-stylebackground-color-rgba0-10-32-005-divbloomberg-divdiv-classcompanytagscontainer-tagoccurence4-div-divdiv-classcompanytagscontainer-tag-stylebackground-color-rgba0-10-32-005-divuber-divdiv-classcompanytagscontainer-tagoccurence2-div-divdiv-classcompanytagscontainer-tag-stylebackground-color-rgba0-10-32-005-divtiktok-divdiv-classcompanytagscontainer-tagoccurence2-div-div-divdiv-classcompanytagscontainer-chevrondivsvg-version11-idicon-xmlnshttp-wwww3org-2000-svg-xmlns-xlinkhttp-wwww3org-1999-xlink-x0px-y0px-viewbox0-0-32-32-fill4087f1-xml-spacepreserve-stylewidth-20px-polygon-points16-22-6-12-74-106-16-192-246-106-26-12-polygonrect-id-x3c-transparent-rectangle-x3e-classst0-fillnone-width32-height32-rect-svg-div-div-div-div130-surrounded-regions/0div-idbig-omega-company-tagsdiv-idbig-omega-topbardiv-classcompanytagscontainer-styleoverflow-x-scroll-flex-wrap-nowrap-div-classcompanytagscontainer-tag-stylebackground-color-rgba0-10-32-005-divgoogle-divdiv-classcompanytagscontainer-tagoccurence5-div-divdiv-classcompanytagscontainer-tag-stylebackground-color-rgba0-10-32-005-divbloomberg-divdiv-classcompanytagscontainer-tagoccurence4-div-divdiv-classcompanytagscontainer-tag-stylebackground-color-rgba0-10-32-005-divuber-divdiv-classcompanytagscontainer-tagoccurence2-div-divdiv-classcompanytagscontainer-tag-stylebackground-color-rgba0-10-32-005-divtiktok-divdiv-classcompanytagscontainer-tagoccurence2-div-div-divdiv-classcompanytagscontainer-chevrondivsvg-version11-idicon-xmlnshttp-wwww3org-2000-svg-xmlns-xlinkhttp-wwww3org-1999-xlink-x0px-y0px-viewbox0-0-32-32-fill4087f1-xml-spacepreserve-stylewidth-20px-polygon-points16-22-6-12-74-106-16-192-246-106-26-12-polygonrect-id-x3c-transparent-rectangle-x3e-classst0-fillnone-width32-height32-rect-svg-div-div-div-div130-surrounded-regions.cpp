class Solution {
private:
    void dfs(int row,int col,vector<vector<int>>& vis,vector<vector<char>>& board,vector<int>& delRow,vector<int>& delCol){
        
        int n=board.size();
        int m=board[0].size();
        
        vis[row][col]=1;
        for(int i=0;i<4;i++){
            int nRow=row+delRow[i];
            int nCol=col+delCol[i];
            if(nRow>=0 && nRow<n && nCol>=0 && nCol<m &&
               !vis[nRow][nCol] && board[nRow][nCol]=='O'){
                dfs(nRow,nCol,vis,board,delRow,delCol);
            }
        }
        
    }
public:
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        
        vector<int> delRow{-1,0,1,0};
        vector<int> delCol{0,1,0,-1};
        
        vector<vector<int>> vis(n,vector<int> (m,0));
        //traverse first row and last row
        for(int i=0;i<m;i++){
            // first row
            if(!vis[0][i] && board[0][i]=='O'){
                dfs(0,i,vis,board,delRow,delCol);
            }
            // last row
            if(!vis[n-1][i] && board[n-1][i]=='O'){
                dfs(n-1,i,vis,board,delRow,delCol);
            }
        }
        for(int i=0;i<n;i++){
            // first col
            if(!vis[i][0] && board[i][0]=='O'){
                dfs(i,0,vis,board,delRow,delCol);
            }
            // last col
            if(!vis[i][m-1] && board[i][m-1]=='O'){
                dfs(i,m-1,vis,board,delRow,delCol);
            }
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && board[i][j]=='O'){
                    board[i][j]='X';
                }
            }
        }
    }
};