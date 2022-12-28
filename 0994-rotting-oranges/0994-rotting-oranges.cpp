class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        
        vector<vector<int>>  vis(n,vector<int>(m));
        int cntFresh=0;
        queue<pair<pair<int,int>,int >> q;

        for(int row=0;row<n;row++){
            for(int col=0;col<m;col++){
                if(grid[row][col]==2){
                    q.push({{row,col},0});
                    vis[row][col]=2;
                }
                else{
                    vis[row][col]=0;
                }
                if(grid[row][col]==1) cntFresh++;
            }
        }
        
        //no doing the bfs
        int time=0;
        vector<int> delRow{-1,0,1,0};
        vector<int> delCol{0,1,0,-1};
        int cnt=0;
        
        while(!q.empty()){
            int r=q.front().first.first;
            int c=q.front().first.second;
            int t=q.front().second;
            q.pop();
            time=max(time,t);
            for(int i=0;i<4;i++){
                int nRow=r+delRow[i];
                int nCol=c+delCol[i];
                if(nRow>=0 && nRow<n && nCol>=0 && nCol<m &&
                   vis[nRow][nCol]==0 && grid[nRow][nCol]==1){
                    q.push({{nRow,nCol},t+1});
                    vis[nRow][nCol]=2;
                    cnt++;
                }
            }
        }
        
        return cnt==cntFresh ?time:-1;
    }
};