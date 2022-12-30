class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<int>> dist(n,vector<int>(n,1e9));
        queue<pair<int,pair<int,int>>> q;
        dist[0][0]=0;
        q.push({1,{0,0}});
        if(grid[0][0]==1){
            return -1;
        }
        if(n==1 && n==1 && grid[0][0]==0){
            return 1;
        }
        vector<int> delRow{0, 0, 1, -1, 1, 1, -1, -1};
        vector<int> delCol{1, -1, 0, 0, -1, 1, -1, 1};
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            int dis=it.first;
            int row=it.second.first;
            int col=it.second.second;
            for(int i=-1;i<=1;i++)
                for(int j=-1;j<=1;j++){
                    int nRow=row+i;
                    int nCol=col+j;
                if(nRow>=0 && nRow<n && nCol>=0 && nCol<n && grid[nRow][nCol]==0 && dis+1 <dist[nRow][nCol]){
                    dist[nRow][nCol]=dis+1;
                    if(nRow==n-1 && nCol==n-1){
                        return dis+1;
                    }
                    q.push({1+dis,{nRow,nCol}});
                }
            }
        }
        return -1;
    }
};