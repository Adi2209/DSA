class oranges{
    public:
    int r,c,t;
    oranges(int row,int col,int time){
        this->r=row;
        this->c=col;
        this->t=time;
    }
};
class Solution {
private:
    void getQueue(queue<oranges>& q,vector<vector<int>>& grid,vector<vector<int>>& vis,int& cntFresh){
        int rotten=2,fresh=1;
        
        for(int row=0;row<grid.size();row++){
            for(int col=0;col<grid[0].size();col++){
                if(grid[row][col]==rotten){
                    q.push({row,col,0});
                    vis[row][col]=rotten;
                }
                if(grid[row][col]==fresh) cntFresh++;
                else{
                    vis[row][col]=0;
                }
            }
        }
    }
    bool isValid(int nRow,int nCol,int rowSize,int colSize){
        return nRow>=0 && nRow<rowSize && nCol>=0 && nCol<colSize;
    }
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rowSize=grid.size();
        int colSize=grid[0].size();
        queue<oranges> q;
        vector<vector<int>> vis(rowSize,vector<int> (colSize));
        int cntFresh=0;
        //getting the queue ready initially and marking the visited array 
        getQueue(q,grid,vis,cntFresh);
        //queue is ready
        //now doing the bfs
        int minTime=0;
        int currCntRotten=0;
        int rotten=2,fresh=1;
        while(!q.empty()){
            int row=q.front().r;
            int col=q.front().c;
            int time=q.front().t;
            q.pop();
            minTime=max(minTime,time);
            vector<int> delRow={-1,0,1,0};
            vector<int> delCol={0,1,0,-1};
            for(int ind=0;ind<4;ind++){
                int nRow=delRow[ind]+row;
                int nCol=delCol[ind]+col;
                if(isValid(nRow,nCol,rowSize,colSize) && vis[nRow][nCol]==0 && grid[nRow][nCol]==fresh){
                    q.push({nRow,nCol,time+1});
                    vis[nRow][nCol]=rotten;
                    currCntRotten++;
                }
            }
        }
        if(currCntRotten!=cntFresh) return -1;
        return minTime;
    }
};