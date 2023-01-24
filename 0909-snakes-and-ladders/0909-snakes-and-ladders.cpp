class Solution {
private:
    vector<int> getDimensions(int curr,int n){
        int row=n-(curr-1)/n-1;
        int col=(curr-1)%n;
        if(row%2==n%2){
            return {row,n-1-col};
        }
        else{
            return {row,col};
        }
    }
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n=board.size();
        vector<vector<bool>> vis(n,vector<bool>(n));
        queue<int> q;
        q.push(1);
        vis[n-1][0]=true;
        int steps=0;
        while(!q.empty()){
            int size=q.size();
            
            for(int ind=0;ind<size;ind++){
                int cell=q.front();
                q.pop();
                if(cell==n*n) return steps;
                for(int move=1;move<=6;move++){
                    if(move+cell>n*n) break;
                    vector<int> pos=getDimensions(move+cell,n);
                    int row=pos[0];
                    int col=pos[1];
                    if(!vis[row][col]){
                        vis[row][col]=true;
                        if(board[row][col]==-1){
                            q.push(move+cell);
                        }
                        else
                            q.push(board[row][col]);
                    }
                }
            }
            steps++;
        }
        return -1;
    }
};